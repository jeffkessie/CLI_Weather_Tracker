#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <cstdlib>  // For getenv

using json = nlohmann::json;

int main() {
    std::string zip;
    std::cout << "Enter ZIP code: ";
    std::cin >> zip;

    // Read the API key from the environment variable
    const char* apiKey = std::getenv("OPENWEATHER_API_KEY");
    if (!apiKey) {
        std::cerr << "❌ ERROR: OPENWEATHER_API_KEY not set in environment.\n";
        return 1;
    }

    std::string url = "https://api.openweathermap.org/data/2.5/weather?zip=" + zip +
                      "&appid=" + apiKey + "&units=imperial";

    cpr::Response r = cpr::Get(cpr::Url{url});

    if (r.status_code == 200) {
        try {
            json weatherData = json::parse(r.text);

            std::string city = weatherData["name"];
            std::string description = weatherData["weather"][0]["description"];
            double temp = weatherData["main"]["temp"];
            double feels_like = weatherData["main"]["feels_like"];
            int humidity = weatherData["main"]["humidity"];

            std::cout << "\n📍 Weather for " << city << "\n";
            std::cout << "-----------------------------\n";
            std::cout << "🌤  Description: " << description << "\n";
            std::cout << "🌡  Temperature: " << temp << " °F\n";
            std::cout << "🤔  Feels Like: " << feels_like << " °F\n";
            std::cout << "💧  Humidity: " << humidity << "%\n";
        } catch (const std::exception& e) {
            std::cerr << "Failed to parse weather data: " << e.what() << "\n";
        }
    } else {
        std::cerr << "❌ Error: " << r.status_code << "\n" << r.text << std::endl;
    }

    return 0;
}
