#define BUFFER_SIZE 45
#define OUTPUT_SIZE 100

const static int16_t filter_taps[BUFFER_SIZE];
uint16_t filteredSignal[OUTPUT_SIZE];

void CircularBuffer() {
  int tempoBuffer[BUFFER_SIZE];
  int adcBufferIndex = 0;
  for(int i=0; i < OUTPUT_SIZE; i++) {
    while((ADC->ADC_ISR & 0x80)==0); // attente de la fin de la conversion
    tempoBuffer[adcBufferIndex] = ADC->ADC_CDR[7]; // sauvegarde du signal Fe = 32Khz dans le buffer 

    adcBufferIndex++;   // incrementation de l'index du buffer cirulaire
    uint16_t sumIndex = adcBufferIndex; // update de l'index pour le bon indexage des valeurs en fonction des coeffs 
    if(adcBufferIndex == BUFFER_SIZE) { // modulo pour remettre à 0 
      adcBufferIndex = 0;
    }
    
    // Calcul du filtrage sur les 15 valeurs du buffer 
    uint32_t acc = 0;
    
    for (int l = 0; l < BUFFER_SIZE; l++) { // multiplication des valeurs du buffer par les coeffs

      // gestion de l'index interne au buffer pour le calcul du filtre
      if( sumIndex > 0 ) {
        sumIndex--;
      } else {
        sumIndex=BUFFER_SIZE-1;
      }
      // calcule du filtre sur 32 bit
      acc += filter_taps[l] * tempoBuffer[sumIndex];
      
    }
    filteredSignal[i] =  acc >> 15; // shift de 15 bit pour repasser sur 16 bit
  }
}
