#ifndef APScan_h
#define APScan_h

#define maxAPScanResults 30

#include <ESP8266WiFi.h>
#include "Mac.h"
#include "MacList.h"

extern String data_getVendor(uint8_t first,uint8_t second,uint8_t third);
extern const bool debug;

class APScan{
  public:
    APScan();
    
    bool start();
    String getResults();
    void select(int num);
    
    String getAPName(int num);
    String getAPEncryption(int num);
    //String getAPVendor(int num);
    String getAPMac(int num);
    bool getAPSelected(int num);
    int getAPRSSI(int num);
    int getAPChannel(int num);

    int getFirstTarget();
    bool isSelected(int num);
    
    int results = 0;
    int selectedSum;
    MacList aps;
  private:
    int channels[maxAPScanResults];
    int rssi[maxAPScanResults];
    char names[maxAPScanResults][33];
    int encryption[maxAPScanResults];

    String getEncryption(int code);

    bool selected[maxAPScanResults];
};

#endif
