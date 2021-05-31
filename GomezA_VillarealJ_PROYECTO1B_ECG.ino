/*
 * NOMBRE: GOMEZ ALEXANDER - VILLAREAL JORGE
 * MATERIA: Sistemas Embebidos
 * PROYECTO: 1
 * CODIGO:Señal ECG
  */
#define tam_sig 600
#define tam_imp 293
extern int ecg_100Hz[tam_sig];
extern int Impulse_response[tam_imp];
int d;
int dac;
int dac1;
int dac2;
int snr;
int output[tam_sig+tam_imp];
void convolution(int *sig_in,int *sig_out,int *imp,int sig_tam,int imp_tam);

int output_signal[tam_sig];
void moving_average (int *sig_in, int *output_signal, int sig_tam, int filter);

void setup() {
  Serial.begin(9600);
}

void loop() {
    convolution((int *)&ecg_100Hz[0], (int *)&output[0],(int *)&Impulse_response[0],
  (int) tam_sig, (int) tam_imp);
   moving_average((int *)&ecg_100Hz[0], (int *)&output_signal[0],(int) tam_sig,11);
  for(d=0;d<tam_sig;d++){
    dac=map(ecg_100Hz[d],0,950,0,255);
    dac2=map(output_signal[d],0,950,0,255);
    dac1=map(output[d],0,1000,0,255);
    snr=map(ecg_100Hz[d]-output_signal[d],0,950,0,255);
    analogWrite(6,dac);
    analogWrite(4,dac2);
    analogWrite(5,dac1);
    analogWrite(3,snr);
    delay(10);
  }
}  

///////////Filtro Fir////////////
void convolution (int *sig_in,int *sig_out,int *imp,int sig_tam,int imp_tam){
  int i,j;
  //poner ceros a vector de salida
  for(i=0;i<(sig_tam+imp_tam);i++){
    sig_out[i]=0;
  }
  for(i=0;i<sig_tam;i++){
    for(j=0;j<imp_tam;j++){
      sig_out[i+j]=sig_out[i+j]+sig_in[i]*imp[j];
    }
  }
}

///////////Suavisado de la señal///////////
void moving_average(int *sig_in, int *output_signal, int sig_tam, int filter){
    int i,j;
  for(i=floor(filter/2);i<sig_tam-floor(filter/2)-1;i++){
    output_signal[i]=0;
    for(j=-floor(filter/2);j<floor(filter/2);j++){
      output_signal[i]=output_signal[i]+sig_in[i+j];
    }
    output_signal[i]=output_signal[i]/filter;
  }
}
