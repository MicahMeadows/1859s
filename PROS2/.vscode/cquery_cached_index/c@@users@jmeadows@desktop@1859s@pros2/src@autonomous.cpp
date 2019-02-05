#include "main.h"

//include test autos
#include "../autos/test/prosautotest.cpp"

//include blue autos
#include "../autos/blue/blue_close001.cpp"
#include "../autos/blue/blue_close001_np.cpp"
#include "../autos/blue/blue_far001.cpp"
#include "../autos/blue/blue_far001_np.cpp"

//include blue autos
#include "../autos/red/red_close001.cpp"
#include "../autos/red/red_close001_np.cpp"
#include "../autos/red/red_far001.cpp"
#include "../autos/red/red_far001_np.cpp"

//include skills autos
#include "../autos/skills/skills001.cpp"


int selectedAuto = 0;

void autonomous() {

    switch(selectedAuto) {
        case 0:
          // do nothing
          break;
        case 1:
          red_close001();
          break;
        case 2:
          red_close001_np();
          break;
        case 3:
          red_far001();
          break;
        case 4:
          red_far001_np();
          break;
        case 5:
          blue_close001();
          break;
        case 6:
          blue_close001_np();
          break;
        case 7:
          blue_far001();
          break;
        case 8:
          blue_far001_np();
          break;
        case 9:
          skills001();
          break;
        }

    }

}
