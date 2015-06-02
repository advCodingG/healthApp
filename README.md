# healthApp

This health app is a database searching tool for obtaining government data on health status in all counties of the United States. 
The raw data (in csv format) was originally downloaded from http://data.gov/. I took the .csv files and converted them to JSON for the convenience of sorting and parsing. 

This openframeworks application can take location input in two different ways:
- Text input window:
You can manually type in your city and state to look up the health status data in your county. 
!['input window screenshot city'](https://github.com/advCodingG/healthApp/blob/master/assets/screenshot2.png)
!['input window screenshot state'](https://github.com/advCodingG/healthApp/blob/master/assets/screenshot3.png)

- Swipe driver's license:
The driver's license in some states comes with a magnetic stripe. This applciation allows you to obtain a report of your data by simply swiping your driver's license.
I used a magTek magnetic card reader and the ofxCreditCardSwiper addon written by Justin Maurer (https://github.com/fakelove/ofxCreditCardSwiper). 
The addon only parses credit card information but I wrote my own method to parse driver's license data and was able to return the city and state information from it.

Here is a sample of the health status report that the user can receive: 
!['input window screenshot report'](https://github.com/advCodingG/healthApp/blob/master/assets/screenshot4.png)

There are five components in this report: 
- Basic information: Name(unavailable if manually input the location), city, state, county
- Health status summary: A quick summary of the overall health status in your county in comparison with the US average
- Relative Health Importance: Relative Health Importance is designed to provide a quick and easy method for assessing one's county health relative to others. Data is presented that highlights favorable and unfavorable health status between peer counties and the nation at large.
(Source from: http://www.nlm.nih.gov/hsrph.html)
- Vunerable Populations: estimates of individuals in designated categories who tend to have poorer health status and more medical needs than the general population.
(Source from: http://www.nlm.nih.gov/hsrph.html)
- Risk Factors: include risk factors for the nation's leading killers of heart disease and cancer as well as personal behaviors and lifestyles choices.
(Source from: http://www.nlm.nih.gov/hsrph.html)

This application is intended to raise awareness about overall health status in specific communities and discover certain patterns that may help the community to improve their policies, personal behaviors and lifestyle, thus incresing the number of healthy population. The data is available on http://data.gov/ but their formats are generally difficult to read. The application is designed also to allow for easier accessibility and transparency of the data to the general public. 
