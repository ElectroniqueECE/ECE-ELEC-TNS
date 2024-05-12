// a modifier 
#define BUFFER_SIZE 1
#define OUTPUT_SIZE 1

const static int16_t filter_taps[BUFFER_SIZE];
uint16_t inputSignal[OUTPUT_SIZE];
uint16_t filteredSignal[OUTPUT_SIZE];

void RIF() {

  // A compléter 
  for (int i = 0; i < BUFFER_SIZE; i++) {
  uint32_t acc = 0;
    
    for (int j = 0; j < BUFFER_SIZE; j++) { // multiplication des valeurs du buffer par les coeffs
    // attribution de l'index pour le filtrage  ( si le premier echantillon à convolutionner du filtre à un index en dehors du tableau, on le fixe à 0)
      uint16_t index = (i - j > 0) ? (i - j) : 0;
      // calcule du filtre sur 32 bit
      acc += filter_taps[j] * inputSignal[index];
        
    }
      filteredSignal[i] =  acc >> 15; // shift de 15 bit pour repasser sur 16 bit
  }
}




