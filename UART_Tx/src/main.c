#include "MCAL_DIO_Header.h"
#include "MGIE_header.h"
#include "MEXTI_header.h"
#include "MCAL_UART_Header.h"
#include "util/delay.h"

U8 Tx_Byte = 0;


///// dip switches variables /////////
U8 Addr1=0; 
U8 Addr2=0;
U8 Data1=0;
U8 Data2=0;
//////////////////////////////////////

U8 AddrBuffer = 0;		// to store Dip switches values 
U8 RxAddr =0;	
U8 DataBuffer=0;		

/// Rx Var ///////
U8 Addr = 0x0F; // fixed address of tx
U8 AckData = 0; // my data
U8 Rx_Byte =0;
U8 Rx_Buffer =0;

/////////////////


/////////// Rx //////////////
void TryReceive(void);
void BlinkYellow(void);
void BlinkGreen(void);
/////////////////////////////

/////// Tx ////////////
void ISR_INT0(void);
///////////////////////

int main ()
{
	// initializing ports directions
	Void_SetPinDir(PORTC,PIN0,OUTPUT); //RX led
	Void_SetPinDir(PORTC,PIN7,OUTPUT); //Tx led
	Void_SetPinDir(PORTD,PIN1,OUTPUT); // Tx pn
     // pins of dip switch
	Void_SetPinDir(PORTA,PIN0,INPUT);
	Void_SetPinDir(PORTA,PIN1,INPUT); 
	Void_SetPinDir(PORTA,PIN2,INPUT); 
	Void_SetPinDir(PORTA,PIN3,INPUT);
    //checking leds of dip switch
	Void_SetPinDir(PORTA,PIN4,OUTPUT); // Tx pn
	Void_SetPinDir(PORTA,PIN5,OUTPUT); //Tx led
	Void_SetPinDir(PORTA,PIN6,OUTPUT);
	Void_SetPinDir(PORTA,PIN7,OUTPUT);
	////////////////// INT 0 for Button For Tx ////////////////////////
	//enabling interrupts
	SetGlobalInteruputEnableBit(MGIE_ON);
	SetEXINTTriggState(INT0,MEXTI_FALLING_EDGE);
	SetEXINTFunction(INT0,&ISR_INT0);	
    ////////////////////////////////////////////////////////////

	Void_UARTConfig(UART_BR_9600BPS,UART_ASYNCHRONOUS,UART_8BIT_MODE,UART_ONE_STOP_BIT,UART_NO_PARITY);
	
	while (1)
	{	
		TryReceive();	
	}
	
	return 0;
}

////////////// Tx Fn ///////////////////////
void ISR_INT0(void)
{
	SetGlobalInteruputEnableBit(MGIE_OFF);	
	Void_SetPinValue(PORTC,PIN7,HIGH);       // Green LED 
	Void_UARTSetMode(UART_Transmitter_Mode);
	
	Addr1 = U8_ReadPinValue(PORTA,PIN0);
	Addr2 = U8_ReadPinValue(PORTA,PIN1);
	Data1 = U8_ReadPinValue(PORTA,PIN2);
	Data2 = U8_ReadPinValue(PORTA,PIN3);

	switch (Addr1)
	{
		case 0:
			switch (Addr2)
			{
				case 0:
					Void_SetPinValue(PORTA,PIN4,LOW);
					Void_SetPinValue(PORTA,PIN5,LOW);
				break;

				case 1:
					Void_SetPinValue(PORTA,PIN4,LOW);
					Void_SetPinValue(PORTA,PIN5,HIGH);

				break;
			default:
				break;
			}
		
		break;
		
		case 1:
			switch (Addr2)
			{
				case 0:
					Void_SetPinValue(PORTA,PIN4,HIGH);
					Void_SetPinValue(PORTA,PIN5,LOW);
				break;

				case 1:
					Void_SetPinValue(PORTA,PIN4,HIGH);
					Void_SetPinValue(PORTA,PIN5,HIGH);
				break;
			default:
				break;
			}
			break;
			
	default:
		break;
	}


	switch (Data1)
	{
		case 0:
			switch (Data2)
			{
				case 0:
					Void_SetPinValue(PORTA,PIN6,LOW);
					Void_SetPinValue(PORTA,PIN7,LOW);
				break;

				case 1:
					Void_SetPinValue(PORTA,PIN6,LOW);
					Void_SetPinValue(PORTA,PIN7,HIGH);
				break;
			default:
				break;
			}
		
		break;
		
		case 1:
			switch (Data2)
			{
				case 0:
					Void_SetPinValue(PORTA,PIN6,HIGH);
					Void_SetPinValue(PORTA,PIN7,LOW);
				break;

				case 1:
					Void_SetPinValue(PORTA,PIN6,HIGH);
					Void_SetPinValue(PORTA,PIN7,HIGH);
				break;
			default:
				break;
			}
			break;
			
	default:
		break;
	}

	AddrBuffer=(Addr1<<0) | (Addr2<<1);
	DataBuffer=(Data2<<0) | (Data1<<1);
    RxAddr=AddrBuffer & 0x0F;
	Tx_Byte=(RxAddr<<4) | DataBuffer;

	Void_UARTWriteFrame(Tx_Byte);	
	Void_UARTFlushBuffer();	
	Void_SetPinValue(PORTC,PIN7,LOW); //Green Led
	Void_UARTSetMode(UART_Receiver_Mode);
	SetGlobalInteruputEnableBit(MGIE_ON);
}
/////////////////////////////////////////////



void TryReceive(void)
{	
	Void_SetPinValue(PORTD,PIN1,HIGH); //Tx	
	Rx_Buffer = U16_UARTReadFrame();
	
		BlinkGreen();
	AckData = Rx_Buffer & 0x0F;			// Must = 1
	if( Addr == (Rx_Buffer >>4) )		// Must = F
	{ 

		if (AckData == 0x01)
		{
			BlinkYellow();
			Void_UARTFlushBuffer();	
			Void_UARTSetMode(UART_Transmitter_Mode);
		}	
	}
	

	return ;
}

void BlinkYellow(void)
{
	Void_SetPinValue(PORTC,PIN7,HIGH); //Green led
	Void_SetPinValue(PORTC,PIN0,HIGH); //Red led
	_delay_ms(50);
	Void_SetPinValue(PORTC,PIN7,LOW); //Green led
	Void_SetPinValue(PORTC,PIN0,LOW); //Red led
	_delay_ms(50);
return;
}

void BlinkGreen(void)
{
	Void_SetPinValue(PORTC,PIN7,HIGH); //Green led
	Void_SetPinValue(PORTC,PIN0,LOW); //Red led
	_delay_ms(50);
	Void_SetPinValue(PORTC,PIN7,LOW); //Green led
	Void_SetPinValue(PORTC,PIN0,LOW); //Red led
	_delay_ms(50);
return;
}

