 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <array>
#include <list>
#include <sstream>

#include <thread>
#include <unistd.h>
#include "json.hpp"

#include "HTTPRequest.hpp"

std::string getJsonWeather(std::string);



using json = nlohmann::json;

enum class Color { BLACK, SILVER, WHITE };

// specjalne makro, ktore pozwoli na automatyczna konwersje wartosci enum do 
// wybranego string-a
NLOHMANN_JSON_SERIALIZE_ENUM(Color, {
	{Color::BLACK, "BLACK"},
	{Color::SILVER, "SILVER"},
	{Color::WHITE, "WHITE"}
});







void getSicaklik(std::string il){
    while (1)
    {
    json j;
    std::string data=getJsonWeather(il);
    
    std::stringstream(data) >>j;
    std::string sehir=j["name"];
    float tmp=j["main"]["temp"];
    std::string sicaklik=std::to_string(tmp);
    std::string kusuratliSicaklik="";
    int i=0;
    int uzunluk=sicaklik.length();
    for(i;i<uzunluk;i++){
        kusuratliSicaklik+=sicaklik[i];
        if(sicaklik[i]=='.'){
            uzunluk=i+3;
        }
    }

    

    std::string sonuc=sehir+":"+kusuratliSicaklik+"\n";
    std::cout<<sonuc;
    
    }
}

std::string getJsonWeather(std::string il){


    try
    {
        std::string url="http://api.openweathermap.org/data/2.5/weather?q="+il+",tr&appid=0a962cc12094a80b1220a761d7ed5ccd&units=metric";
        std::string method = "GET";
        std::string arguments;
        std::string output;
        http::InternetProtocol protocol = http::InternetProtocol::V4;

        

        http::Request request(url, protocol);

        const http::Response response = request.send(method, arguments, {
            "Content-Type: application/x-www-form-urlencoded",
            "User-Agent: runscope/0.1"
        });

        if (response.status == http::Response::STATUS_OK &&
            !output.empty())
        {
            std::ofstream outfile(output, std::ofstream::binary);
            outfile.write(reinterpret_cast<const char*>(response.body.data()),
                          static_cast<std::streamsize>(response.body.size()));
        }
        else{
            
            return std::string(response.body.begin(), response.body.end());

        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
        return "HATA";
    }

    return "HATA";


}

int main()
{
    
    
    std::thread istanbul(getSicaklik,"istanbul");
    std::thread izmir(getSicaklik,"izmir");
    std::thread ankara(getSicaklik,"ankara");
    std::thread antalya(getSicaklik,"antalya");
    std::thread bursa(getSicaklik,"bursa");
    std::thread manisa(getSicaklik,"manisa");
    std::thread mardin(getSicaklik,"mardin");
    std::thread yozgat(getSicaklik,"yozgat");
    std::thread adana(getSicaklik,"adana");
    std::thread adiyaman(getSicaklik,"adıyaman");
    std::thread afyon(getSicaklik,"afyon");
    std::thread agri(getSicaklik,"ağrı");
    std::thread aksaray(getSicaklik,"aksaray");
    std::thread ardahan(getSicaklik,"ardahan");
    std::thread artvin(getSicaklik,"artvin");
    std::thread aydin(getSicaklik,"aydın");
    std::thread balikkesir(getSicaklik,"balıkesir");
    std::thread bartin(getSicaklik,"bartın");
    std::thread batman(getSicaklik,"batman");
    std::thread bayburt(getSicaklik,"bayburt");
    std::thread bilecik(getSicaklik,"bilecik");
    std::thread bingol(getSicaklik,"bingöl");
    std::thread bitlis(getSicaklik,"bitlis");
    std::thread burdur(getSicaklik,"burdur");
    std::thread bolu(getSicaklik,"bolu");
    std::thread corum(getSicaklik,"çorum");
    std::thread diyarbakir(getSicaklik,"diyarbakır");
    std::thread edirne(getSicaklik,"edirne");
    std::thread erzurum(getSicaklik,"erzurum");
    std::thread sivas(getSicaklik,"sivas");
    std::thread giresun(getSicaklik,"giresun");
    std::thread hatay(getSicaklik,"hatay");
    std::thread ordu(getSicaklik,"ordu");
    std::thread kilis(getSicaklik,"kilis");
    std::thread van(getSicaklik,"van");
    std::thread tunceli(getSicaklik,"tunceli");
    

    tunceli.join();
    van.join();
    kilis.join();
    ordu.join();
    hatay.join();
    giresun.join();
    sivas.join();
    erzurum.join();
    edirne.join();
    diyarbakir.join();
    corum.join();
    bolu.join();
    burdur.join();
    bitlis.join();
    bingol.join();
    bilecik.join();
    bayburt.join();
    batman.join();
    bartin.join();
    balikkesir.join();
    aydin.join();
    artvin.join();
    ardahan.join();
    aksaray.join();
    agri.join();
    afyon.join();
    adiyaman.join();
    adana.join();
    yozgat.join();
    mardin.join();
    manisa.join();
    istanbul.join();
    izmir.join();
    ankara.join();
    antalya.join();
    bursa.join();

    
    
   
	return 0;
}