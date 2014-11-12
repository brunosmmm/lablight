#include "RotEnc.h"

#define ROTENC_DETECT 50

#define ROTENC_CYCLE 100 //intervalo em milissegundos entre os ciclos de controle
#define ROTENC_SUBCYCLE 1 

#define ROTENC_LED1 0x02
#define ROTENC_LED2 0x04
#define ROTENC_LED3 0x08
#define ROTENC_LED4 0x10
#define ROTENC_LED5 0x20
#define ROTENC_LED6 0x40
#define ROTENC_LED7 0x80

#define ROTENC_A 0
#define ROTENC_B 1
#define ROTENC_C 2

//estados da maquina de decodificação do encoder rotativo
#define ROTENC_S0 0x00
#define ROTENC_S1 0x01
#define ROTENC_S2 0x02
#define ROTENC_S3 0x03

#define ROTENC_FAN 0x80

#define DIVFACTOR 18
#define SHAMT 3

#define ROTENC_STEP 5 //passo do controle da intensidade do LED de potência

#define FAN_THRESH 400 //limite máximo para acionamento da ventoinha de resfriamento do LED de potência

#define ROTENC_COOLINT 120000 //intervalo em milissegundos que define o período de resfriamento

//Estrutura com principais variáveis do sistema
static struct SENCDATA{
	
	byte INTENS[7];       //intensidade de cada led no pwm por software
	word VAL;            //valor armazenado representando intensidade do LED de potência
	dword LASTSUBCYCLE; //tempo do ultimo subciclo de pwm por software
	dword LASTCYCLE;   //tempo do ultimo ciclo de controle do sistema
	byte SUBCYCLE;    //contador de número de ciclos do pwm por software
	
	byte ENCSTATUS;  //estado da máquina de estados que decodifica o encoder rotativo
	
	dword COOLDOWN; //tempo em milissegundos do inicio do ciclo de resfriamento
	
	byte SYSSTATUS; //status do sistema
	
	
} ENCDATA;


void ROTENC_Init(void)
{
	//inicializa variáveis
	ENCDATA.INTENS[0] = 0;
	ENCDATA.INTENS[1] = 0;
	ENCDATA.INTENS[2] = 0;
	ENCDATA.INTENS[3] = 0;
	ENCDATA.INTENS[4] = 0;
	ENCDATA.INTENS[5] = 0;
	ENCDATA.INTENS[6] = 0;
	
	ENCDATA.VAL = 0;
	
	ENCDATA.LASTSUBCYCLE = 0;
	ENCDATA.LASTCYCLE = 0;
	ENCDATA.SUBCYCLE = 0;
	
	ENCDATA.ENCSTATUS = 0;
	
	ENCDATA.COOLDOWN = 0;
	
	ENCDATA.SYSSTATUS = 0x00;
	
	HC595_Clear(); //Limpa registrador
	
}

int8_t read_encoder()
{
  static int8_t enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
  static uint8_t old_AB = 0;
  /**/
  old_AB <<= 2;                   //remember previous state
  old_AB |= ( ENCDATA.ENCSTATUS & 0x03 );  //add current state
  return ( enc_states[( old_AB & 0x0f )]);
}

static void ROTENC_FLogic(void)
{
	
	if (FCONTROL_GetVal())
	{
		//ventilador ligado
		if (ENCDATA.VAL < FAN_THRESH) 
		{
			
			//intensidade foi reduzida
			
			if (ENCDATA.ENCSTATUS & ROTENC_FAN) {
				
				//verifica o intervalo de resfriamento
				
				if ((ENCDATA.COOLDOWN + ROTENC_COOLINT) < GET_TimeMS()) {
					
					//período de resfriamento acabou
					
					ENCDATA.ENCSTATUS &= ~ROTENC_FAN; //desmarca o estado
					FCONTROL_ClrVal(); //desliga ventilador
				}
				
				
			} else {
				
				//a intensidade foi diminuida abaixo do limite agora; inicia intervalo de resfriamento
				
				ENCDATA.ENCSTATUS |= ROTENC_FAN; //flaga o estado
				ENCDATA.COOLDOWN = GET_TimeMS(); //marca início do intervalo
				
			}
			
		}
		
		
		
	} else {
		
		if (!(ENCDATA.ENCSTATUS & ROTENC_FAN)) {
			if (ENCDATA.VAL >= FAN_THRESH) FCONTROL_SetVal(); //liga ventilador
		}
		
		
	}
	
	
	
}

void ROTENC_Cycle(void)
{
	
	byte reg = 0x00;
	//byte newStatus = ((ROTA_GetVal()<<ROTENC_A) | (ROTB_GetVal()<<ROTENC_B) | (ROTC_GetVal()<<ROTENC_C));
	int8_t status = read_encoder();
	word temp = 0x0000;
	
	//SOFTWARE PWM
	
	if ((ENCDATA.LASTSUBCYCLE + ROTENC_SUBCYCLE) < GET_TimeMS())
	{
	
		
		if (ENCDATA.INTENS[0] > ENCDATA.SUBCYCLE) reg |= ROTENC_LED1;
		else reg &= ~ROTENC_LED1;
		
		if (ENCDATA.INTENS[1] > ENCDATA.SUBCYCLE) reg |= ROTENC_LED2;
		else reg &= ~ROTENC_LED2;
		
		if (ENCDATA.INTENS[2] > ENCDATA.SUBCYCLE) reg |= ROTENC_LED3;
		else reg &= ~ROTENC_LED3;
		
		if (ENCDATA.INTENS[3] > ENCDATA.SUBCYCLE) reg |= ROTENC_LED4;
		else reg &= ~ROTENC_LED4;
		
		if (ENCDATA.INTENS[4] > ENCDATA.SUBCYCLE) reg |= ROTENC_LED5;
		else reg &= ~ROTENC_LED5;
		
		if (ENCDATA.INTENS[5] > ENCDATA.SUBCYCLE) reg |= ROTENC_LED6;
		else reg &= ~ROTENC_LED6;
		
		if (ENCDATA.INTENS[6] > ENCDATA.SUBCYCLE) reg |= ROTENC_LED7;
		else reg &= ~ROTENC_LED7;
		
		if (ENCDATA.SUBCYCLE < 10) ENCDATA.SUBCYCLE++;
		else ENCDATA.SUBCYCLE = 0;
	
		HC595_SendByteAndLatch(reg);
		
		ENCDATA.LASTSUBCYCLE = GET_TimeMS();
	}
	
	//CICLO PRINCIPAL
	//if ((ENCDATA.LASTCYCLE + ROTENC_DETECT) < GET_TimeMS())
	//{
	
	if (!(ENCDATA.SYSSTATUS & ROTENC_SYS_REMCTL)) { //sistema em modo controle remoto ignora entrada
	
		if (status == 1)
		{
			
			//if (ENCDATA.ROTCOUNT == 4) {
			//	if (ENCDATA.INTENS[6] < 10) ENCDATA.INTENS[6]++;
			//	ENCDATA.ROTCOUNT = 0;
			//} else ENCDATA.ROTCOUNT++;
			
			
			if (ENCDATA.VAL < (1024 - ROTENC_STEP)) ENCDATA.VAL+=ROTENC_STEP;
			
			
		} else if (status == -1)
		{
			//if (ENCDATA.ROTCOUNT == 4) {
			//	if (ENCDATA.INTENS[6] > 0) ENCDATA.INTENS[6]--;
			//	ENCDATA.ROTCOUNT = 0;
			//} else ENCDATA.ROTCOUNT++;
			
			if (ENCDATA.VAL > 0) ENCDATA.VAL-=ROTENC_STEP;
		}
		
	}	
		
		//DETERMINA LEDS
		temp = (ENCDATA.VAL >> SHAMT) / DIVFACTOR;
		
		if (temp > 0) {
			
			if (temp == 1) {
				
				//LED2
				ENCDATA.INTENS[1] = ((ENCDATA.VAL >> SHAMT) % DIVFACTOR);
				
			}
			
			if (temp == 2)
			{
				
				//LED3
				ENCDATA.INTENS[2] = ((ENCDATA.VAL >> SHAMT) % DIVFACTOR);
			}
			
			if (temp == 3)
			{
				
				ENCDATA.INTENS[3] = ((ENCDATA.VAL >> SHAMT) % DIVFACTOR);
			}
			
			if (temp == 4)
			{
				
				ENCDATA.INTENS[4] = ((ENCDATA.VAL >> SHAMT) % DIVFACTOR);
			}
			
			if (temp == 5)
			{
				
				ENCDATA.INTENS[5] = ((ENCDATA.VAL >> SHAMT) % DIVFACTOR);
			}
			
			if (temp == 6)
			{
				
				ENCDATA.INTENS[6] = ((ENCDATA.VAL >> SHAMT) % DIVFACTOR);
			}
			
			
		} else {
			
			//LED1
			ENCDATA.INTENS[0] = ((ENCDATA.VAL >> SHAMT) % DIVFACTOR);
			
		}
		
		//INTENISDADE LED POTENCIA
		if (status) {
			
			//só atualiza PWM se tiver ocorrido mudança de status
			
			(void)PWM1_SetRatio16((~(ENCDATA.VAL)<<6) | 0x003F);
		}
		
		
		ROTENC_FLogic(); //logica do ventilador
		
		
		//ENCDATA.ENCSTATUS = newStatus;
		
		//ENCDATA.LASTCYCLE = GET_TimeMS();
		
		if (ROTA_GetVal()) ENCDATA.ENCSTATUS |= (1<<ROTENC_A);
		else ENCDATA.ENCSTATUS &= ~(1<<ROTENC_A);
		
		if (ROTB_GetVal()) ENCDATA.ENCSTATUS |= (1<<ROTENC_B);
		else ENCDATA.ENCSTATUS &= ~(1<<ROTENC_B);
		
		if (ROTC_GetVal()) ENCDATA.ENCSTATUS |= (1<<ROTENC_C);
		else ENCDATA.ENCSTATUS &= ~(1<<ROTENC_C);
		
	//}
		
		//ENCDATA.LASTSTATUS = status;
	
	
	
}

byte ROTENC_TRANS(byte b)
{
	byte ret = 0x00;
	
	if (b & 0x01) ret |= ROTENC_LED1;
	if (b & 0x02) ret |= ROTENC_LED2;
	if (b & 0x04) ret |= ROTENC_LED3;
	if (b & 0x08) ret |= ROTENC_LED4;
	if (b & 0x10) ret |= ROTENC_LED5;
	if (b & 0x20) ret |= ROTENC_LED6;
	if (b & 0x40) ret |= ROTENC_LED7;
	
	return ret;
	
}

void ROTENC_ResetCounters(void)
{
	
	ENCDATA.LASTSUBCYCLE = 0;
	ENCDATA.LASTCYCLE = 0;
}
