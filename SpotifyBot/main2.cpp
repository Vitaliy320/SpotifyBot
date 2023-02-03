//#include "stdafx.h"
//#include <curl\curl.h>
//#include <iostream>
//#include <stdio.h>
//#include <string>
//
//using namespace std;
//CURL* curl;
//CURLcode res;
//long responsecode;
//
//string url = "https://www.bosch-iot-insights.com/data-recorder-service/v2/";
//string project = "demo";
//const char* headerAccept = "Accept: application/json";
//const char* headerContentType = "Content-Type: application/json";
////Encode  username:password in Base64 and input the string after Basic
//const char* headerAuthorization = "Authorization: Basic Zm9vOmJhcg==";
//
////Define a proxy connection if required. Otherwise set the option null;
////If you are inside your company network, proxy authentication may be required. Otherwise, you can remove this from the example. This is an example for a Bosch internal proxy.
//const char* proxyUrl;
////input your proxy Authentification in following syntax:  username:password
//const char* proxyAuth;
////set postFields to send a Post request otherwise libcurl send a get request
//string postFields = "";
//
//void addHttpHeaders(CURL* curl) {
//    struct curl_slist* headerlist = NULL;
//    headerlist = curl_slist_append(headerlist, headerAccept);
//    headerlist = curl_slist_append(headerlist, headerAuthorization);
//    headerlist = curl_slist_append(headerlist, headerContentType);
//    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
//}
//
//void proxySettings(CURL* curl) {
//
//    curl_easy_setopt(curl, CURLOPT_PROXY, proxyUrl);
//    curl_easy_setopt(curl, CURLOPT_PROXYUSERPWD, proxyAuth);
//}
//
//CURLcode request(CURL* curl, string postFields) {
//
//    string concartUrl = url + project;
//    const char* completeUrl = concartUrl.c_str();
//    curl_easy_setopt(curl, CURLOPT_URL, completeUrl);
//    //This option disable the certifcate Check. It isn't recommended to use this option!
//    //curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
//
//    //set postFields for post method otherwise libcurl is using http get by default
//    if (!postFields.empty()) {
//        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields);
//    }
//    return curl_easy_perform(curl);
//}
//
//boolean checkProjectState() {
//    curl = curl_easy_init();
//    if (curl) {
//        addHttpHeaders(curl);
//
//        if ((proxyUrl != NULL) && (proxyUrl[0] == '\0')) {
//            proxySettings(curl);
//        }
//        res = request(curl, postFields);
//
//        /* Check for errors */
//        if (res != CURLE_OK) {
//            fprintf(stderr, "curl_easy_perform() failed: %s\n",
//                curl_easy_strerror(res));
//            curl_easy_cleanup(curl);
//            return false;
//        }
//        else {
//            curl_easy_cleanup(curl);
//            return true;
//        }
//    }
//    return false;
//}
//void sendData() {
//
//    curl = curl_easy_init();
//
//    if (curl) {
//
//        addHttpHeaders(curl);
//        if ((proxyUrl != NULL) && (proxyUrl[0] == '\0')) {
//            proxySettings(curl);
//        }
//        res = request(curl, postFields);
//
//        /* Check for errors */
//        if (res != CURLE_OK) {
//            fprintf(stderr, "curl_easy_perform() failed: %s\n",
//                curl_easy_strerror(res));
//        }
//        else {
//            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responsecode);
//            if (responsecode == 201) {
//                cout << "successful upload" << endl;
//            }
//            else if (responsecode == 304) {
//                cout << "Uploaded data is marked as duplicate and wasn't proccessed" << endl;
//            }
//            else {
//                cout << "something works wrong. Server answer with status code: " << responsecode << endl;
//            }
//        }
//
//
//        curl_easy_cleanup(curl);
//    }
//}
//int main() {
//    curl_global_init(CURL_GLOBAL_ALL);
//    if (checkProjectState()) {
//
//        postFields = "{\"Hello\": \"World\"}";
//        sendData();
//
//        cout << "press any key to exit" << endl;
//        string wait;
//        getline(cin, wait);
//        curl_global_cleanup();
//        return 0;
//
//    }
//    else {
//        cout << "press any key to exit" << endl;
//        string wait;
//        getline(cin, wait);
//        curl_global_cleanup();
//        return 1;
//    }
//
//}