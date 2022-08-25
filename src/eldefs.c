//
// Created by hosein nahari on 8/26/22.
//

#include "eldefs.h"

char slf = 1;
char lef = 1;
char door_check = 2;
char RUN = 0;
char slf_conter = 0;
char lef_conter = 0;


char ListOfErrors[][ERR_MESSAGE_LEN] = {"", "1-Input Err", "2-Fto Act", "3-CA1&CAN Err", "4-Lock(68) Open",
                                        "5-DO Input Act", "6-Seristop Open", "7-Over Load", "8-Door Open 66",
                                        "9-Door Time", "10-Cut Safety 68", "11-Cntactr Err", "12-SLF & LEF Err",
                                        "13-LEF Err", "14-Move Time ", "15-5kt Open", "16-Network D.C.",
                                        "17-Direction Err", "18-Leving Err", "19-CAN Not Detect", "20-CA1 Not Detect",
                                        "21-Num Err", "22-Seristp Bypas", "23-FDR Err", "24-CPH Err", "25-4BS Err",
                                        "26-DC_Key Act", "27-CA1 Open", "28-CAN Open", "29-Emr Act", "30-Req Time",
                                        "31-Noisy Net", "32-Error(32)", "33-Cnt Load Err", "34-Out Of LEF",
                                        "35-Lock 68", "36-Car_Stp Act", "37-Speed Err", "38-Ins & Rev Err",
                                        "39-Duplex D.C.", "40-SLF Err", "41-Cnt Load/F", "42-Cnt Load/S", "43-CFC Cut",
                                        "44-Car_Led Short"};


unsigned char MenuItems[51][16] = {"Welcome", "1.Max Floor :", "2.Numerator :", "3.Door Type :", "4.Slf Flag :",
                                   "5.Dc Time :", "6.Do Time :", "7.Light Time :", "8.Move Time :", "9.Up/DN Delay :",
                                   "10.Dm Delay :", "11.Door In Park:", "12.Park Floor:", "13.Base Floor:",
                                   "14.Dir Speed Delay", "15.Detect Floor :", "16.Lift Logic:", "17.Display Adj:",
                                   "18.Relay Status:", "19.Error List:", "20.Adj Tow Door", "21.Delete Error",
                                   "22.Duplex Mode:", "23.Move Counter", "24.Spr(1) Input:", "25.Spr(2) Input:",
                                   "26.Coding:", "27.Canceling :", "28.Hyd Relevel :", "29.Advance Open:",
                                   "30.Set Rdo_Out:", "31.Carcodec:", "32.Verify Mode:", "33.Password:",
                                   "34.Timer Hyd:", "35.Lift Type:", "36.Short Floor:", "37.Flag Set:",
                                   "38.System Test:", "39.Safety Check:", "40.Load Default:", "41.Lift Test:",
                                   "42.Speech Help:", "43.Lev Up Delay:", "44.Lev Dn Delay:", "45.Rev Delay:",
                                   "46.Ins&Rev Err:", "47.CFC&CFS Mode:", "48.Speech Mode:", "49.Speaker Vol:",
                                   "50.Speech Album:"};

unsigned char SubItems[59][16] = {"Pardis Control", "Value : #$", "(Auto Setup)", "2.Semi Door", "1.First Flag",
                                  "Value : #$  S", "Value : #$  S", "Value : #$  S", "Value : #$  S", "Value : #.$ S",
                                  "Value : #.$ S", "1.Open Mode", "P: #   T: $ Min", "Value : #$", "Value : #.$ S",
                                  "3.Fast Speed", "1.Collect Down", "Floor:$  Num:% ", "5.UPS Mode", "Last 30 Error",
                                  "(Relay DO/DC)", "(Remove List)", "0.Disable", "(No Access)", "0.Control Load",
                                  "2.Emr (nc)", "(More Safe)", "1.Disabble", "1.Disable", "0.Disable", "0.Do_Relay",
                                  "0.Enable", "(Show Changed)", "1.Disable", "Value : #$  S", "1. 3VF board",
                                  "(Middle Speed)", "(Num Slf To Stp)", "(Board Test)", "0.Enable", "(Rst Parameter)",
                                  "0.Disable", "1.Disable", "Value : #$  S", "Value : #$  S", "Value : #$  S",
                                  "0.Enable", "0. NO", "1.Parallel", "0.Disable", "0.Disable"};