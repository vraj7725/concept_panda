#include <iostream>

using namespace std;

int main() {
  int volumeOfA = 5, volumeOfB = 3, volumeToBeCalculated = 4, count = 0, tempVolume = volumeOfB, volumeLeftInA = 0, volumeLeftInB = 0;

  do {
    count ++;
    if (count == 1) {
     cout << "pouring water to cup a and transferring to cup b \n";
    } else {
     cout << "pouring water to cup a \n";
    }
    
    if ( volumeOfA == volumeToBeCalculated || volumeOfB == volumeToBeCalculated) {
      break;
    }

    volumeLeftInA = volumeOfA  - tempVolume;
    count ++;
    if ( volumeLeftInA <= volumeOfA - volumeOfB) {
        cout <<"emptying cup b \n";
    }
    volumeLeftInB = volumeLeftInA;
    cout<<"Transferring water left in A to B \n";
    tempVolume = volumeOfB - volumeLeftInB;
    count ++;
  }while (volumeLeftInA != volumeToBeCalculated || volumeLeftInB != volumeToBeCalculated);

  cout<<"Volume of container is " << volumeToBeCalculated << "ml";
}
