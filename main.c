#include "stdio.h"
#include "FOC.h"

int main()
{
    float V_a = 0;
    float V_b = 0;
    float V_c = 0;

    float V_q = 6;
    float V_d = 0;
    float V_Alpha = 0;
    float V_Beta = 0;

    float theta = 0;

    float Udc = 12;
    float Tx = 0;
    float Ty = 0;
    float Ts = 1;

    float Tcmd1 = 0;
    float Tcmd2 = 0;
    float Tcmd3 = 0;

    int sector = 0;


    for (theta = 0; theta < 2*3.14159f; theta += 0.1f)
    {
        Invt_Park(V_q, theta, &V_Alpha, &V_Beta);
        SVPWM_GetSector_SetPeriod(V_Alpha, V_Beta, &Tx, &Ty, Ts, Udc, &sector);
        SVPWM_SetTcmd(&Tcmd1, &Tcmd2, &Tcmd3, Tx, Ty, Ts, sector);
        // printf("%f %f %f %d\n", 360*theta/(2*3.14159f), Tx, Ty, sector);
        printf("%f %f %f %f %d\n", Tcmd1, Tcmd2, Tcmd3, 360*theta/(2*3.14159f), sector);
    }
    

    return 0;
}