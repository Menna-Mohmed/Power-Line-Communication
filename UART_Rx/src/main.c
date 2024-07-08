#include "MCAL_DIO_Header.h"
#include "MGIE_header.h"
#include "MEXTI_header.h"
#include "MCAL_UART_Header.h"
#include "util/delay.h"


void TryReceive(void);				// main receiving Fn 
void ACKSend(void);

///// LED Indication Functions //////
void BlinkYellow(void);
void BlinkGreen(void);
void BlinkRed(void);
void DisplayData(U8 ReceivedData);		// display Received data on LEDs 
///////////////////////////////////////


U8 Rx_Addr = 0x0F; // go to addr
U8 AckData = 0x01; 	// ack to send to transmitter
U8 Ack_Byte = 0;    // byte sent to transmitter for ACK


U8 Addr = 0x01; 	// my addr (change from module to module) 
U8 Rx_Buffer = 0;  	// received byte Buffer 
U8 Data = 0;		//store receive data		

int main ()
{
	

	Void_SetPinDir(PORTC,PIN0,OUTPUT); //Green led
	Void_SetPinDir(PORTA,PIN0,OUTPUT); //Red led


	/////// Data received indications ////////////
	Void_SetPinDir(PORTA,PIN5,OUTPUT); 
	Void_SetPinDir(PORTA,PIN6,OUTPUT); 
	Void_SetPinDir(PORTA,PIN7,OUTPUT); 
	//////////////////////////////////////////////


	Void_SetPinDir(PORTD,PIN1,OUTPUT); // Tx pin
    Void_UARTConfig(UART_BR_9600BPS,UART_ASYNCHRONOUS,UART_8BIT_MODE,UART_ONE_STOP_BIT,UART_NO_PARITY);
	Void_SetPinValue(PORTD,PIN1,HIGH); //Tx


	
	Ack_Byte = (Rx_Addr<<4) | AckData;

	while (1)
	{
		Void_SetPinValue(PORTA,PIN0,LOW); //Green Led
		Void_SetPinValue(PORTC,PIN0,HIGH);//Red led
		TryReceive();
	}
	return 0;
}




void TryReceive(void)
{	
	Void_UARTFlushBuffer();
    Void_UARTSetMode(UART_Receiver_Mode);
	Void_SetPinValue(PORTD,PIN1,HIGH); //Tx

	Rx_Buffer = U16_UARTReadFrame(); 	// receiving Frame
	Void_UARTFlushBuffer();			

	Data = Rx_Buffer & 0x0F;		// extracting data 
	if( Addr == (Rx_Buffer >>4))  
	{
		BlinkGreen();		// indicates that addr is correct 

		DisplayData(Data); 	// displaying received data on leds 
		ACKSend();
	}

	return ;
}

void BlinkYellow(void)
{
	Void_SetPinValue(PORTA,PIN0,HIGH); //Green led
	Void_SetPinValue(PORTC,PIN0,HIGH); //Red led
	_delay_ms(50);
	Void_SetPinValue(PORTA,PIN0,LOW); //Green led
	Void_SetPinValue(PORTC,PIN0,LOW); //Red led
	_delay_ms(50);
return;
}


void BlinkGreen(void)
{
	Void_SetPinValue(PORTA,PIN0,HIGH); //Green led
	Void_SetPinValue(PORTC,PIN0,LOW); //Red led
	_delay_ms(50);
	Void_SetPinValue(PORTA,PIN0,LOW); //Green led
	Void_SetPinValue(PORTC,PIN0,LOW); //Red led
	_delay_ms(50);
return;
}

void BlinkRed(void)
{
	Void_SetPinValue(PORTC,PIN0,HIGH); //Red led
	_delay_ms(50);
	Void_SetPinValue(PORTC,PIN0,LOW); //Red led
	_delay_ms(50);
	return;
}

void ACKSend(void)
{
	Void_UARTFlushBuffer();
    Void_UARTSetMode(UART_Transmitter_Mode);
	Void_UARTWriteFrame(Ack_Byte);
	return;
}

void DisplayData(U8 ReceivedData)
{
	switch (ReceivedData)
	{
		case 1:
			Void_SetPinValue(PORTA,PIN5,HIGH);
			Void_SetPinValue(PORTA,PIN6,LOW);
			Void_SetPinValue(PORTA,PIN7,LOW);

		break;

		case 2:
			Void_SetPinValue(PORTA,PIN5,HIGH);
			Void_SetPinValue(PORTA,PIN6,HIGH);
			Void_SetPinValue(PORTA,PIN7,LOW);

		break;

		case 3:
			Void_SetPinValue(PORTA,PIN5,HIGH);
			Void_SetPinValue(PORTA,PIN6,HIGH);
			Void_SetPinValue(PORTA,PIN7,HIGH);

		break;

	default:

			Void_SetPinValue(PORTA,PIN5,LOW);
			Void_SetPinValue(PORTA,PIN6,LOW);
			Void_SetPinValue(PORTA,PIN7,LOW);

		break;
	}



	return;
}