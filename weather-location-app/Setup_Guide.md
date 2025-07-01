# 🌦️ Standalone C++ Weather App (ZIP Code Based)

Fetch real-time weather by U.S. ZIP code from the terminal using the OpenWeatherMap API.

---

## ✅ Prerequisites


- C++17 or later
- Git
- curl (library, not just CLI)
- Internet connection
- [OpenWeatherMap API key](https://openweathermap.org/api)
- [vcpkg](https://github.com/microsoft/vcpkg) for dependency management


---

## 📁 Motivation:

"The heat demanded two things: stay inside and do something useful. So I built this rather than sweat into oblivion. Thank you, relentless summer sun."

## 🛠️ Step-by-Step: How to Run It

1. ✅ Make Sure the C++ Binary is Compiled

```cpp
   g++ -o weather <file-name> 
```

2. ✅ Give the Binary Permission to Run

```cpp
   chmod +x weather
```

3. ✅ Set Your API Key

```cpp
   export OPENWEATHER_API_KEY=your_actual_api_key_here

```

4. ✅ Install vcpkg

```
git clone https://github.com/microsoft/vcpkg.git


./bootstrap-vcpkg.sh      # For macOS/Linux
# OR
.\bootstrap-vcpkg.bat     # For Windows
```
5. 🧱 Build the App
```cpp
g++ weather.cpp -I. -I.\vcpkg\installed\x64-windows\include -L.\vcpkg\installed\x64-windows\lib -lcurl -o weather.exe

```

6. ▶ Run the App

```cpp
./weather 21216


```

## OUTPUT EXAMPLE:
```

📍 Location: Baltimore, US
🌡️  Temperature: 75.2°F
🌤️  Condition: scattered clouds


```



