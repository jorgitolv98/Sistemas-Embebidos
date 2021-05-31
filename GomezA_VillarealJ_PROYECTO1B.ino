/*
 * NOMBRE: GOMEZ ALAXANDER_VILLAREAL JORGE
 * MATERIA: Sistemas Embebidos
 * PROYECTO: 1
 * CODIGO:Señal Flex sensor aco
  */
#define tam_sig 900
extern int  flex_sensor_aco[tam_sig];
int d;
int dac;
int dac2;
float dac1;
int snr;
int output_signal[tam_sig];
void medio_movil (int *sig_in, int *output_signal, int sig_tam, int filter);

float output[tam_sig];
void mme(int *sig_in, float*output, int sig_tam, float alpha);
void setup() {
  Serial.begin(9600);

}

void loop() {
  mme((int *)&flex_sensor_aco[0],(float *)&output[0],(int) tam_sig,0.5);
   medio_movil((int *)&flex_sensor_aco[0], (int *)&output_signal[0],(int) tam_sig,9);
  for(d=0;d<tam_sig;d++){
    dac=map(flex_sensor_aco[d],0,200,0,255);
    dac2=map(output_signal[d],0,200,0,255);  
    dac1=map(output[d],0,200,0,255);
    snr=map(flex_sensor_aco[d]-output_signal[d],0,950,0,255);
    analogWrite(6,dac);
    analogWrite(5,dac1);
    analogWrite(4,dac2);
    analogWrite(3,snr);
    delay(10);
  }
}
///////////Medio Movil///////////
void medio_movil(int *sig_in, int *output_signal, int sig_tam, int filter){
    int i,j;
  for(i=floor(filter/2);i<sig_tam-floor(filter/2)-1;i++){
    output_signal[i]=0;
    for(j=-floor(filter/2);j<floor(filter/2);j++){
      output_signal[i]=output_signal[i]+sig_in[i+j];
    }
    output_signal[i]=output_signal[i]/filter;
  }
}
///////////////////Promedio Exponencial///////////
void mme(int *sig_in, float*output, int sig_tam, float alpha){
  int i,j;
  output[i]=0;
  for(i=0;i<sig_tam;i++){
  //𝑦(2) =∝ 𝑥2 + 𝑦(𝑛 − 1)(1−∝)
  output[i]=(alpha*sig_in[i])+(1-alpha)*output[i];
  }
  
}
