#ifndef SADNESS_H
#define SADNESS_H

typedef enum Sadness {
   NO_SADNESS,
   MILD_SADNESS,
   MODERATE_SADNESS,
   SEVERE_SADNESS,
} Sadness;

void getMood (Sadness *mood);
const char *getMoodName(int mood);

#endif // SADNESS_H
