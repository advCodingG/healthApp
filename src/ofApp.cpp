#include "ofApp.h"
#include <stdio.h>
#include <string>
#include <cstring>


// Margin constants
const float kLeftMargin                 =       100.0f;
const float kTopMargin                  =       100.0f;

// Spacing Constants
const float kVerticalBtnSpacing         =       30.0f;
const float kTextToBtnSpacing           =       5.0f;

// Sizing Constants
ofVec2f     kBtnSize                    =       ofVec2f( 100.0f, 50.0f );

// Color Constants
ofColor     kBtnColor                   =       ofColor( 206.0f, 32.0f, 41.0f );


//--------------------------------------------------------------
void ofApp::setup(){
   // mToggleDebugBtn = ofRectangle( kLeftMargin, kTopMargin, kBtnSize.x, kBtnSize.y );
    ccScan.setup();
    ccScan.enableDebugMode();
    
    ofTrueTypeFont::setGlobalDpi(72);
    
    Bariol.loadFont("Bariol.ttf", 20, true, true);
    BariolBig.loadFont("Bariol.ttf", 30, true, true);
    BariolSmall.loadFont("Bariol.ttf", 14, true, true);
    Bariol.setLineHeight(18.0f);
    Bariol.setLetterSpacing(1.05);
    BariolBig.setLineHeight(18.0f);
    BariolBig.setLetterSpacing(1.05);
    BariolSmall.setLineHeight(18.0f);
    BariolSmall.setLetterSpacing(1.08);
    
  
    // load the health summary json data
    std::string summary = "summary.json";
    bool parsingSuccessful = summaryResult.open(summary);
    
    if (parsingSuccessful)
    {
       // ofLogNotice("ofApp::setup") << summaryResult.getRawString();
        
        // now write pretty print
        if (!summaryResult.save("summaryResult_output_pretty.json", true))
        {
            //ofLogNotice("ofApp::setup") << "summaryResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
            //ofLogNotice("ofApp::setup") << "summaryResult_output_pretty.json written successfully.";
        }
        
        // now write without pretty print
        if (!summaryResult.save("summaryResult_output_fast.json", false))
        {
           // ofLogNotice("ofApp::setup") << "summaryResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
            //ofLogNotice("ofApp::setup") << "summaryResult_output_pretty.json written successfully.";
        }
        
    }
    else
    {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }
    
// load the relative health importance json data
    std::string RHI = "relativeHealthImportance.json";
    bool parsingSuccessful2 = RHIResult.open(RHI);
    
    if (parsingSuccessful2)
    {
        //ofLogNotice("ofApp::setup") << RHIResult.getRawString();
        
        // now write pretty print
        if (!RHIResult.save("RHIResult_output_pretty.json", true))
        {
            //ofLogNotice("ofApp::setup") << "RHIResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
            //ofLogNotice("ofApp::setup") << "RHIResult_output_pretty.json written successfully.";
        }
        
        // now write without pretty print
        if (!RHIResult.save("RHIResult_output_fast.json", false))
        {
            //ofLogNotice("ofApp::setup") << "RHIResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
            //ofLogNotice("ofApp::setup") << "RHIResult_output_pretty.json written successfully.";
        }
        
    }
    else
    {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }
    
//load the vulnerable population data
    std::string vulnerable = "vulnerable.json";
    bool parsingSuccessful3 = vulnerableResult.open(vulnerable);
    
    if (parsingSuccessful3)
    {
        //ofLogNotice("ofApp::setup") << vulnerableResult.getRawString();
        
        // now write pretty print
        if (!vulnerableResult.save("vulnerableResult_output_pretty.json", true))
        {
           // ofLogNotice("ofApp::setup") << "vulnerableResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
           // ofLogNotice("ofApp::setup") << "vulnerableResult_output_pretty.json written successfully.";
        }
        
        // now write without pretty print
        if (!vulnerableResult.save("vulnerableResult_output_fast.json", false))
        {
           // ofLogNotice("ofApp::setup") << "vulnerableResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
           // ofLogNotice("ofApp::setup") << "vulnerableResult_output_pretty.json written successfully.";
        }
        
    }
    else
    {
       ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }
//load the risk factor data
    
    std::string riskFactor = "riskFactor.json";
    bool parsingSuccessful5 = riskFactorResult.open(riskFactor);
    
    if (parsingSuccessful5)
    {
        //ofLogNotice("ofApp::setup") << riskFactorResult.getRawString();
        
        // now write pretty print
        if (!riskFactorResult.save("riskFactorResult_output_pretty.json", true))
        {
           // ofLogNotice("ofApp::setup") << "riskFactorResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
           // ofLogNotice("ofApp::setup") << "riskFactorResult_output_pretty.json written successfully.";
        }
        
        // now write without pretty print
        if (!riskFactorResult.save("riskFactorResult_output_fast.json", false))
        {
           // ofLogNotice("ofApp::setup") << "riskFactorResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
           // ofLogNotice("ofApp::setup") << "riskFactorResult_output_pretty.json written successfully.";
        }
        
    }
    else
    {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }
    
//load the state and county data
    
    std::string countyJSON = "stateCounty.json";
    bool parsingSuccessful6 = countyResult.open(countyJSON);
    
    if (parsingSuccessful6)
    {
        //ofLogNotice("ofApp::setup") << riskFactorResult.getRawString();
        
        // now write pretty print
        if (!countyResult.save("countyResult_output_pretty.json", true))
        {
            // ofLogNotice("ofApp::setup") << "countyResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
           //  ofLogNotice("ofApp::setup") << "countyResult_output_pretty.json written successfully.";
        }
        
        // now write without pretty print
        if (!countyResult.save("countyResult_output_fast.json", false))
        {
           //  ofLogNotice("ofApp::setup") << "countyResult_output_pretty.json written unsuccessfully.";
        }
        else
        {
            // ofLogNotice("ofApp::setup") << "countyResult_output_pretty.json written successfully.";
        }
        
    }
    else
    {
         ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ccScan.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofColor color1 = ofColor(178, 232, 255);
    ofColor color2 = ofColor(255, 236, 162);
    ofColor color3 = ofColor(242, 148, 148);
    ofColor color4 = ofColor(187, 232, 185);

    
    ofColor colorArray [4]= {color1, color2, color3,color4};
    ofFill();
    for (int i = 0; i < 4; i++) {
        ofSetColor(colorArray[i]);
          ofRect(0, 68 + 175 * i, ofGetWidth(), 175 );
    }
    
    ofSetColor(0);
    
    //Part 1: basic info
    ccScan.draw();
    
    //The original Credit Card Swipe addon by Justin Maurer only parses credit card info
    //Please see the getBasicInfo() method in CreditCardScanner.cpp for how I parsed driver's license data
    std::string state = ccScan.getState();
    std::string city = ofToLower(ccScan.getCity());
    std::string name = ccScan.getName();

  //  cout << "ofApp: " << state << "," << city << endl;
    
  // Driver's license does not have county information, but the health data is organized by counties.
  // so we need to look up the county by city and state in another JSON file
    
    std::string countyID;

    if(city.length() > 0 && state.length() > 0){
            for(int h = 0; h < countyResult.size(); h++){
        
                std::string cityVal = countyResult[h]["ShortName(City)"].asString();
                
                //we need to clean up the city name so that it does not contain any white-space character
                //because the city data from the driver's license does not have any
                std::string cityVal_new = "";
                for(int j = 0; j < cityVal.length(); j++){
                    if (!isspace(cityVal[j])){
                        cityVal_new += cityVal[j];
                    }
                }
                // cout << cityVal << endl;

                //look up the county information based on city and state
                if(ofToLower(cityVal_new) == city && countyResult[h]["ISO31662A2(State)"] == state )
                {
                    countyID = countyResult[h]["FIPS 6-4(County(s))"].asString();
                    Bariol.drawString("Hi, "+ name, 20, 40 );
                    Bariol.drawString("Your location is: " + city + ", " + state, 200,  40);
                    Bariol.drawString("The data below is shown for: " + countyResult[h]["FormalName(County(s))"].asString(), 550, 40 );
                }
            }
    }else{
    
        BariolBig.drawString("Swipe your driver's license to continue", ofGetWidth()/2 - 300, ofGetHeight()/2);
    }
    //cout << countyID << "," << state <<endl;
    
    //Part 2: health summary
    //fetch the appropriate data from the health summary json file based on county ID
    
   
    for(int i = 0; i < summaryResult.size(); i++){
        
        if(summaryResult[i]["County_FIPS_Code"].asString() == countyID &&
           summaryResult[i]["CHSI_State_Abbr"].asString() == state){
            
            BariolBig.drawString("Health Summary for Your Community", 20, 100);
            
            std::string ALE = summaryResult[i]["ALE"].asString();
            std::string US_ALE = summaryResult[i]["US_ALE"].asString();
            if (ALE == "-2222.2" ||
                ALE == "-2222" ||
                ALE == "-2" ||
                ALE == "-1111.1" ||
                ALE == "-1111" ||
                ALE == "-1"
                ) {
                    ALE = "Unavailable";
                    }
            
            if (US_ALE == "-2222.2" ||
                US_ALE == "-2222" ||
                US_ALE == "-2" ||
                US_ALE == "-1111.1" ||
                US_ALE == "-1111" ||
                US_ALE == "-1"
                ) {
                US_ALE = "Unavailable";
            }
            
            
            Bariol.drawString("Average life expectancy: " + ALE, 100, 140);
            Bariol.drawString("US average: " + US_ALE, 700, 140);
            
            
            if(ofToFloat( ALE) < ofToFloat( US_ALE)){
                
                Bariol.drawString("<", 500, 140);
                
            }else if(ofToFloat( ALE) > ofToFloat( US_ALE)){
                
                Bariol.drawString(">", 500, 140);
                
            } else {
                
                Bariol.drawString("=", 500, 140);
                
            }

            
            std::string healthStatus = summaryResult[i]["Health_Status"].asString();
            std::string US_HealthStatus = summaryResult[i]["US_Health_Status"].asString();
            if (healthStatus == "-2222.2" ||
                healthStatus == "-2222" ||
                healthStatus == "-2" ||
                healthStatus == "-1111.1" ||
                healthStatus == "-1111" ||
                healthStatus == "-1"
                ) {
                healthStatus = "Unavailable";
            }
            
            if (US_HealthStatus == "-2222.2" ||
                US_HealthStatus == "-2222" ||
                US_HealthStatus == "-2" ||
                US_HealthStatus == "-1111.1" ||
                US_HealthStatus == "-1111" ||
                US_HealthStatus == "-1"
                ) {
                US_HealthStatus = "Unavailable";
            }
            
            
            Bariol.drawString("Self-rated health status: " + healthStatus, 100, 180);
            Bariol.drawString("US average: " + US_HealthStatus, 700, 180);
            
            
            if(ofToFloat( healthStatus) < ofToFloat( US_HealthStatus)){
                
                Bariol.drawString("<", 500, 180);
                
            }else if(ofToFloat( healthStatus) > ofToFloat( US_HealthStatus)){
                
                Bariol.drawString(">", 500, 180);
                
            } else {
                
                Bariol.drawString("=", 500, 180);
                
            }
            
            std::string unHealthyDays = summaryResult[i]["Unhealthy_Days"].asString();
            std::string US_unHealthyDays = summaryResult[i]["US_Unhealthy_Days"].asString();
            if (unHealthyDays == "-2222.2" ||
                unHealthyDays == "-2222" ||
                unHealthyDays == "-2" ||
                unHealthyDays == "-1111.1" ||
                unHealthyDays == "-1111" ||
                unHealthyDays == "-1"
                ) {
                unHealthyDays = "Unavailable";
            }
            
            if (US_unHealthyDays == "-2222.2" ||
                US_unHealthyDays == "-2222" ||
                US_unHealthyDays == "-2" ||
                US_unHealthyDays == "-1111.1" ||
                US_unHealthyDays == "-1111" ||
                US_unHealthyDays == "-1"
                ) {
                US_unHealthyDays = "Unavailable";
            }
            
            
            Bariol.drawString("Number of unhealthy days in past month: " + unHealthyDays, 60, 220);
            Bariol.drawString("US average: " + US_unHealthyDays, 700, 220);
            
            
            if( ofToFloat( unHealthyDays) < ofToFloat( US_unHealthyDays)){
                
                Bariol.drawString("<", 500, 220);
                
            }else if(ofToFloat( unHealthyDays) > ofToFloat( US_unHealthyDays)){
                
                Bariol.drawString(">", 500, 220);
                
            } else {
                
                Bariol.drawString("=", 500, 220);
                
            }

        }
    }
    
    //Part 2: Relative Health Indicator: Relative Health Importance is designed to provide a quick and easy method for assessing one's county health relative to others. Data is presented that highlights favorable and unfavorable health status between peer counties and the nation at large.
    for(int j = 0; j < RHIResult.size(); j++){
        
        
        if(summaryResult[j]["County_FIPS_Code"].asString() == countyID &&
           summaryResult[j]["CHSI_State_Abbr"].asString() == state){
            
            BariolBig.drawString("Relative Health Importance", 20, 280);
            std::string unfavorableDesc ="The amount of people who have the following health statuses is above US average: ";
            
            std::string unfavorable = "";
            
            if (RHIResult[j]["RHI_Infant_Mortality_Ind"] == 6 || RHIResult[j]["RHI_Infant_Mortality_Ind"] == 8) {
                unfavorable += "infant mortality, ";
            }
            
            if (RHIResult[j]["RHI_Brst_Cancer_Ind"] == 6 || RHIResult[j]["RHI_Brst_Cancer_Ind"] == 8) {
                unfavorable += "breast cancer (female), ";
            }
            if (RHIResult[j]["RHI_Col_Cancer_Ind"] == 6 || RHIResult[j]["RHI_Col_Cancer_Ind"] == 8) {
                unfavorable += "colon cancer, ";
            }
            
            if (RHIResult[j]["RHI_CHD_Ind"] == 6 || RHIResult[j]["RHI_CHD_Ind"] ==8) {
                unfavorable += "coronary heart disease, ";
            }
            
            if (RHIResult[j]["RHI_Homicide_Ind"] == 6 || RHIResult[j]["RHI_Homicide_Ind"] ==8) {
                unfavorable += "homicide, ";
            }
            if (RHIResult[j]["RHI_Lung_Cancer_Ind"] == 6 || RHIResult[j]["RHI_Lung_Cancer_Ind"] ==8) {
                unfavorable += "lung cancer, ";
            }
            
            if (RHIResult[j]["RHI_MVA_Ind"] == 6 || RHIResult[j]["RHI_MVA_Ind"] == 8) {
                unfavorable += "motor vehicle injuries, ";
            }
            
            if (RHIResult[j]["RHI_Stroke_Ind"] == 6 || RHIResult[j]["RHI_Stroke_Ind"] ==8) {
                unfavorable += "stroke, ";
            }
            
            if (RHIResult[j]["RHI_Suicide_Ind"] == 6 || RHIResult[j]["RHI_Suicide_Ind"] ==8) {
                unfavorable += "suicide, ";
            }
            
            
            if (RHIResult[j]["RHI_Injury_Ind"] == 6 || RHIResult[j]["RHI_Injury_Ind"] == 8) {
                unfavorable += "unintentional injury, ";
            }
            
            Bariol.drawString( unfavorableDesc, 20, 310);
            //remove the last comma in the string

            unfavorable.erase(unfavorable.find_last_of(","), 1);
            //if the string gets too long and doesn't fit in the window, switch to a smaller font size
            if(Bariol.stringWidth(unfavorable) >= ofGetWidth()){
                BariolSmall.drawString( unfavorable, 20, 330);
                
            }else{
                Bariol.drawString( unfavorable, 20, 330);
                
            }
            
            std::string favorableDesc ="The amount of people who have the following health statuses is below US average: ";
            
            std::string favorable = "";

            if (RHIResult[j]["RHI_Infant_Mortality_Ind"] == 5 || RHIResult[j]["RHI_Infant_Mortality_Ind"] == 7) {
                favorable += "infant mortality, ";
            }
            
            if (RHIResult[j]["RHI_Brst_Cancer_Ind"] == 5 || RHIResult[j]["RHI_Brst_Cancer_Ind"] == 7) {
                favorable += "breast cancer (female), ";
            }
            if (RHIResult[j]["RHI_Col_Cancer_Ind"] == 5 || RHIResult[j]["RHI_Col_Cancer_Ind"] == 7) {
                favorable += "colon cancer, ";
            }
            
            if (RHIResult[j]["RHI_CHD_Ind"] == 5 || RHIResult[j]["RHI_CHD_Ind"] == 7) {
                favorable += "coronary heart disease, ";
            }
            
            if (RHIResult[j]["RHI_Homicide_Ind"] == 5 || RHIResult[j]["RHI_Homicide_Ind"] ==7) {
                favorable += "homicide, ";
            }
            if (RHIResult[j]["RHI_Lung_Cancer_Ind"] == 5 || RHIResult[j]["RHI_Lung_Cancer_Ind"] == 7) {
                favorable += "lung cancer, ";
            }
            
            if (RHIResult[j]["RHI_MVA_Ind"] == 5 || RHIResult[j]["RHI_MVA_Ind"] == 7) {
                favorable += "motor vehicle injuries, ";
            }
            
            if (RHIResult[j]["RHI_Stroke_Ind"] == 5 || RHIResult[j]["RHI_Stroke_Ind"] ==7) {
                favorable += "stroke, ";
            }
            
            if (RHIResult[j]["RHI_Suicide_Ind"] == 5 || RHIResult[j]["RHI_Suicide_Ind"] == 7) {
                favorable += "suicide,";
            }
            
            
            if (RHIResult[j]["RHI_Injury_Ind"] == 5 || RHIResult[j]["RHI_Injury_Ind"] == 7) {
                favorable += "unintentional injury, ";
            }

            Bariol.drawString( favorableDesc, 20, 360);
            //remove the last comma in the string
            favorable.erase(favorable.find_last_of(","), 1);

            //if the string gets too long and doesn't fit in the window, switch to a smaller font size
            if(Bariol.stringWidth(favorable) >= ofGetWidth()){
                 BariolSmall.drawString( favorable, 20, 380);
            
            }else{
                Bariol.drawString( favorable, 20, 380);

            }
            
        }
        
    }
    
//Part 3: Vunerable Populations are estimates of individuals in designated categories who tend to have poorer health status and more medical needs than the general population.
    
    
    for(int i = 0; i < vulnerableResult.size(); i++){
      
        
        if(summaryResult[i]["County_FIPS_Code"].asString() == countyID &&
           summaryResult[i]["CHSI_State_Abbr"].asString() == state){
            BariolBig.drawString("Vunerable Populations", 20, 455);
          
            if(vulnerableResult[i]["No_HS_Diploma"] == -2222.2 ||
               vulnerableResult[i]["No_HS_Diploma"] == -2222 ||
               vulnerableResult[i]["No_HS_Diploma"] == -2 ||
               vulnerableResult[i]["No_HS_Diploma"] == -1111.1 ||
               vulnerableResult[i]["No_HS_Diploma"] == -1111 ||
               vulnerableResult[i]["No_HS_Diploma"] == -1
               ){
                //do nothing
                }else{
                    float NoHSRate = round(vulnerableResult[i]["No_HS_Diploma"].asFloat()/vulnerableResult[i]["Population_Size"].asFloat() * 100) ;
                    Bariol.drawString("No High School Diploma Rate (Age > 25) : " + ofToString(NoHSRate) + "%", 20, 480);
                }
            
            if(vulnerableResult[i]["Unemployed"] == -9999){
                //do nothing
            }else{
                float UnemploymentRate = round(vulnerableResult[i]["Unemployed"].asFloat()/vulnerableResult[i]["Population_Size"].asFloat() * 100);
            
                Bariol.drawString("Unemployment rate: " + ofToString(UnemploymentRate) + "%", 20, 500);
            }
            
            
            if(vulnerableResult[i]["Sev_Work_Disabled"] == -2222.2 ||
               vulnerableResult[i]["Sev_Work_Disabled"] == -2222 ||
               vulnerableResult[i]["Sev_Work_Disabled"] == -2 ||
               vulnerableResult[i]["Sev_Work_Disabled"] == -1111.1 ||
               vulnerableResult[i]["Sev_Work_Disabled"] == -1111 ||
               vulnerableResult[i]["Sev_Work_Disabled"] == -1
               ){
                //do nothing
            }else{
                float disabledRate = round(vulnerableResult[i]["Sev_Work_Disabled"].asFloat()/vulnerableResult[i]["Population_Size"].asFloat() * 100 );
            
                Bariol.drawString("Severely work disabled rate: " + ofToString(disabledRate) + "%", 20, 520);
            }
            
            if(vulnerableResult[i]["Major_Depression"] == -2222.2 ||
               vulnerableResult[i]["Major_Depression"] == -2222 ||
               vulnerableResult[i]["Major_Depression"] == -2 ||
               vulnerableResult[i]["Major_Depression"] == -1111.1 ||
               vulnerableResult[i]["Major_Depression"] == -1111 ||
               vulnerableResult[i]["Major_Depression"] == -1
               ){
                //do nothing
            }else{
                float depressionRate = round(vulnerableResult[i]["Major_Depression"].asFloat()/vulnerableResult[i]["Population_Size"].asFloat() * 100 );
            
                Bariol.drawString("Major depression rate: " + ofToString(depressionRate) + "%", 20, 540);
            }
            
            
            if(vulnerableResult[i]["Recent_Drug_Use"] == -2222.2 ||
               vulnerableResult[i]["Recent_Drug_Use"] == -2222 ||
               vulnerableResult[i]["Recent_Drug_Use"] == -2 ||
               vulnerableResult[i]["Recent_Drug_Use"] == -1111.1 ||
               vulnerableResult[i]["Recent_Drug_Use"] == -1111 ||
               vulnerableResult[i]["Recent_Drug_Use"] == -1
               ){
                //do nothing
            }else{
                float drugRate = round(vulnerableResult[i]["Recent_Drug_Use"].asFloat()/vulnerableResult[i]["Population_Size"].asFloat() * 100 );
            
                Bariol.drawString("Recent Drug User rate: " + ofToString(drugRate) + "%", 20, 560);
            
            }
     
        }
    }
//Part 5: Risk Factors for Premature Death include risk factors for the nation's leading killers of heart disease and cancer as well as personal behaviors and lifestyles choices.
    
    for(int i = 0; i < riskFactorResult.size(); i++){
        
        if(summaryResult[i]["County_FIPS_Code"].asString() == countyID &&
           summaryResult[i]["CHSI_State_Abbr"].asString() == state){
            
            BariolBig.drawString("Risk Factors", 20, 630);
            if(riskFactorResult[i]["No_Exercise"] == -2222.2 ||
               riskFactorResult[i]["No_Exercise"] == -2222 ||
               riskFactorResult[i]["No_Exercise"] == -2 ||
               riskFactorResult[i]["No_Exercise"] == -1111.1 ||
               riskFactorResult[i]["No_Exercise"] == -1111 ||
               riskFactorResult[i]["No_Exercise"] == -1
               ){
                //do nothing
            }else{
            Bariol.drawString("No exercise rate: " + riskFactorResult[i]["No_Exercise"].asString() + "%", 20, 660);
                
            }
            
            
            if(riskFactorResult[i]["Few_Fruit_Veg"] == -2222.2 ||
               riskFactorResult[i]["Few_Fruit_Veg"] == -2222 ||
               riskFactorResult[i]["Few_Fruit_Veg"] == -2 ||
               riskFactorResult[i]["Few_Fruit_Veg"] == -1111.1 ||
               riskFactorResult[i]["Few_Fruit_Veg"] == -1111 ||
               riskFactorResult[i]["Few_Fruit_Veg"] == -1
               ){
                //do nothing
            }else{
            Bariol.drawString("Few Fruit/Vegetable rate: " +riskFactorResult[i]["Few_Fruit_Veg"].asString()+ "%", 20, 680);
                
            }
            
            if(riskFactorResult[i]["Obesity"] == -2222.2 ||
               riskFactorResult[i]["Obesity"] == -2222 ||
               riskFactorResult[i]["Obesity"] == -2 ||
               riskFactorResult[i]["Obesity"] == -1111.1 ||
               riskFactorResult[i]["Obesity"] == -1111 ||
               riskFactorResult[i]["Obesity"] == -1
               ){
                //do nothing
            }else{
            Bariol.drawString("Obesity rate: " +riskFactorResult[i]["Obesity"].asString()+ "%", 20, 700);
            }
            
            if(riskFactorResult[i]["High_Blood_Pres"] == -2222.2 ||
               riskFactorResult[i]["High_Blood_Pres"] == -2222 ||
               riskFactorResult[i]["High_Blood_Pres"] == -2 ||
               riskFactorResult[i]["High_Blood_Pres"] == -1111.1 ||
               riskFactorResult[i]["High_Blood_Pres"] == -1111 ||
               riskFactorResult[i]["High_Blood_Pres"] == -1
               ){
                //do nothing
            }else{
            Bariol.drawString("High blood pressure rate: " +riskFactorResult[i]["High_Blood_Pres"].asString()+ "%", 20, 720);
            }
            
            if(riskFactorResult[i]["Smoker"] == -2222.2 ||
               riskFactorResult[i]["Smoker"] == -2222 ||
               riskFactorResult[i]["Smoker"] == -2 ||
               riskFactorResult[i]["Smoker"] == -1111.1 ||
               riskFactorResult[i]["Smoker"] == -1111 ||
               riskFactorResult[i]["Smoker"] == -1
               ){
                //do nothing
            }else{
            Bariol.drawString("Smoker rate: " +riskFactorResult[i]["Smoker"].asString()+ "%", 20, 740);
            }
            
            if(riskFactorResult[i]["Diabetes"] == -2222.2 ||
               riskFactorResult[i]["Diabetes"] == -2222 ||
               riskFactorResult[i]["Diabetes"] == -2 ||
               riskFactorResult[i]["Diabetes"] == -1111.1 ||
               riskFactorResult[i]["Diabetes"] == -1111 ||
               riskFactorResult[i]["Diabetes"] == -1
               ){
                //do nothing
            }else{
            Bariol.drawString("Diabetes rate: " +riskFactorResult[i]["Diabetes"].asString()+ "%", 20, 760);
            }
            
            
   
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
