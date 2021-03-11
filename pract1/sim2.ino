void setup() {
  // put your setup code here, to run once:
 DDRB = DDRB | B10000000;// Data Direction Register B: Inputs 0-6, Output 7
}

void loop() {
  // put your main code here, to run repeatedly:
  asm (
    "inicio: \n\t"
    "sbi 0x05,0x07 \n\t"    //se pone el alto el bit 7 del puerto B
    "sbis 0x03,0x06 \n\t"   //se compara si el puerto 12 
                            (Port B - bit 6)esta envíando señla o no
    "call tiempo \n\t"      //si lo está entonces manda a llamar
                            tiempo una ocasión extra
    "call tiempo \n\t"      
    "cbi 0x05,0x07 \n\t"    //se pone en bajo el bit 7 del puerto B
    "call tiempo \n\t"
    "sbis 0x03,0x06 \n\t"   
    "call tiempo \n\t"
    "rjmp inicio\n\t"
   
    
    "tiempo: \n\t"
    "LDI r22, 45 \n\t"
    "LOOP_3: \n\t"
    "LDI r21, 255 \n\t"
    "LOOP_2: \n\t"
    "LDI r20, 255 \n\t"
    "LOOP_1: \n\t"
    "DEC r20 \n\t"
    "BRNE LOOP_1 \n\t"
    "DEC r21 \n\t"
    "BRNE LOOP_2 \n\t"
    "DEC r22 \n\t"
    "BRNE LOOP_3 \n\t"
    "ret \n\t"

    );
}