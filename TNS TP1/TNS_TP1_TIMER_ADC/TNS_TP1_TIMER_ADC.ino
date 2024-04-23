#define PinTimer 2
#define RC 0 //Todo: Définir la valeur trouver pour le registre de comparaison

void setupTimer(){
  /*Todo:
    Partie 1:
    1 - Activer le périphérique Timer
    2 - Configurer le registre TC_CMR
    3 - Valeur du registre de comparaison
    4 - Activation de l'interruption par RC Compare
    5 - Activation de l'interruption dans le NVIC de la Due
  */
}

void TC0_Handler(){
  /*Todo:
    Partie 1:
    1 - Lire et effacer le drapeau d'interruption
    2 - Changer l'état du pin timer pour analyser la fréquence du timer sur oscilloscope

    Partie 2:
    1 - Lancer manuellement la conversion de l'ADC

  */

}

void setupADC(){
  /* Todo:
    Partie 2:
    1 - Activer le périphérique ADC
    2 - Configurer l'ADC dans ADC_MR
    3 - Selectionner le channel d'entrée de l'ADC 
  */

}

void setupDAC(){
  PMC->PMC_PCER1 |= PMC_PCER1_PID38; // Active le périphérique DAC
  // Configure le DAC en mode normal
  DACC->DACC_MR = DACC_MR_TRGEN_DIS // Désactive le déclencheur externe
                  | DACC_MR_USER_SEL_CHANNEL1 // select canal 1 // DACC_MR_USER_SEL_CHANNEL0
                  | DACC_MR_WORD_HALF // Largeur de mot de 16 bits (0 - 4095)
                  | DACC_MR_REFRESH(1) // Temps de rafraîchissement (dans les cycles de l'horloge du périphérique)
                  | DACC_MR_STARTUP_8 // Temps de démarrage (8 * 6 cycles)
                  | DACC_MR_MAXS; // Utilise le contrôleur DMA pour les transferts DAC
  // Active le canal 1 du DAC
  DACC->DACC_CHER = DACC_CHER_CH1;// DACC_CHER_CH0
  DACC->DACC_IER |= DACC_IER_EOC;
  // Active l'interruption DACC_IRQn dans le NVIC 
  NVIC_EnableIRQ(DACC_IRQn);
}

void DACC_Handler() {
  DACC->DACC_ISR;  //  effacer le register d’état “status register”
}

void setup() {
  Serial.begin(460800); //Baud rate au maximum de l'Arduino Due
  pinMode(PinTimer, OUTPUT); //Pin pour analyser la freq du timer
  /* Todo:
    Partie 1:
    1 - setup le timer et le lancer
    Partie 2: 
    1 - setup l'ADC 
    2 - setup le DAC
  */

}

void loop() {
  //Partie 2:
  /*if(ADC->ISR & XXXXXXXX){ //Masque binaire à compléter en fonction du channel de l'ADC
    //Todo: 
    //Partie 2:
    // 1 - Afficher des valeurs de l'ADC sur le moniteur série
    // 2 - Sortie sur le DAC des valeurs de l'ADC avec les lignes suivantes:
    // DACC->DACC_CDR = DACC_CDR_DATA(valeur_de_l'ADC);
    // while (!(DACC->DACC_ISR & DACC_ISR_TXRDY));
  }*/
}
