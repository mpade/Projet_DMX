#include <Vector.h>

#define ELEMENT_COUNT_MAX 4096

class spotData
{
  char storage_array[ELEMENT_COUNT_MAX];
  Vector<char> buffer;
  public : 
    spotData();
    int GetNb();
    String GetData(int);
    int GetNbPota(String);
    int GetAdrTrame(String);
};
