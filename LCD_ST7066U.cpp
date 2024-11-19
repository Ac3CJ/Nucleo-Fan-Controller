/*
 *     File Name: LCD_ST7066U.cpp
 *       Version: 0.1
 *          Date: 2016-04-18
 *        Author: Luis F Rodriguez
 *       Company: BIOS (Biological Innovation and Optimization Services)
 *
 *   Description: This is the source code to be included in any project utilizing a
 *                16x2 LCD screen based on the ST7066U processor being controlled with
 *                an mbed-enabled LPC11U68. This file expands on the declarations given
 *                in the accompanying header file.
 *
 */

/*
 * MARK: Include Files
 * Any header files to be included in the project are found in this section.
 */
 
#include "mbed.h"
#include "LCD_ST7066U.h"

/*
 * MARK: Function Definition
 * This section contains the definition for all of the functions
 * declared in the header file.
 */

LCD::LCD(PinName rs, PinName e, PinName d0, PinName d1, PinName d2, PinName d3, PinName d4, PinName d5, PinName d6, PinName d7): _rs(rs), _e(e), _dataBus(d0,d1,d2,d3,d4,d5,d6,d7), _row(0), _column(0)
{
    ThisThread::sleep_for(100ms);
    LCD::init();
}

void LCD::init(){
    ThisThread::sleep_for(100ms);
    
    _e = 0;
    writeCommand(functionSet);
    writeCommand(functionSet);

    writeCommand(setCursor);
    writeCommand(setDisplay);
    writeCommand(entryModeSet);
    writeCommand(clearDisplay);
}

void LCD::writeTime(){
    _e = 1;
    ThisThread::sleep_for(1ms);
    _e = 0;
}

void LCD::writeData(char value){
    _dataBus.write(value);
    writeTime();
}

void LCD::writeCommand(char value){
    _rs = 0;
    writeData(value);
}

void LCD::writeCharacter(char value){
    _rs = 1;
    writeData(value);
}

void LCD::clear(){
    writeCommand(clearDisplay);
    _row = 0;
    _column = 0;
}

void LCD::character(int row, int column,  char c) {
    uint8_t a = address(row, column);
    writeCommand(a);
    writeCharacter(c);
    //Update position
    if(_column < columns())
        _column++;
    if (_column >= columns()){
        if (_row == 0){
            _column = 0;
            _row++;
        }
        else{
            _row = 0;
            _column = 0;
        }
    }
}

void LCD::write(const char* text) {
    _row = 0;
    _column = 0;
    int characterAmount =0;
    
    for(int i = 0; text[i] != '\0'; i++)
        characterAmount++;
        
    for (int i = 0; i < characterAmount && i < rows() * columns(); i++){
        character(_row, _column, text[i]);
    }
}

void LCD::writeLine(const char* text, int line) {
    _row = line;
    _column = 0;
    int characterAmount =0;
    
    for(int i = 0; text[i] != '\0'; i++)
        characterAmount++;
        
    for (int i = 0; i < characterAmount  && i < columns(); i++){
        character(_row, _column, text[i]);
    }
}

void LCD::writeCharacter(const char c, int row, int column) {
    locate(row, column);
    character(_row, _column, c);
}

void LCD::writeCharacters(const char* text, int row, int column) {
    locate(row, column);
    
    int characterAmount =0;
    
    for(int i = 0; text[i] != '\0'; i++)
        characterAmount++;
        
    for (int i = 0; i < characterAmount  && i < columns() - column; i++){
        character(_row, _column, text[i]);
    }
}
int LCD::address(int row, int column){
    if(row < rows() && column < columns())
        return 0x80 + (row * 0x40) + column;
    else
        return 0x80;
}

void LCD::locate(int row, int column) {
     _row = row;
    _column = column;
}

void LCD::writeTest() {

}