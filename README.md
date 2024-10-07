# 🌡️ Electric Water Heater – Adjustable Temperature Control (Proteus Simulation)

An embedded system simulated in **Proteus**, designed to control water temperature between **35°C** and **75°C**. Temperature settings are saved and restored using **external EEPROM**, ensuring persistence across power cycles.

## 🚀 Features

- **📈 Adjustable Temperature**:  
  Set the water temperature between **35°C** and **75°C** in 5°C increments.

- **🎮 Simple Controls**:  
  Use the "Up" and "Down" buttons to adjust the temperature. First button press enters temperature setting mode.

- **💾 Persistent Settings**:  
  The last set temperature is saved in **EEPROM** and restored when powered back on.

- **⚙️ Initial Temperature**:  
  The system starts with a default temperature of **60°C**.

---

## 🛠️ Simulation Setup (Proteus)

- **Proteus Simulation**:  
  The entire system is developed and validated using **Proteus** simulation software.

- **Hardware Components**:  
  - Microcontroller (e.g., simulated Arduino)
  - External EEPROM (e.g., 24CXX series)
  - Simulated "Up" and "Down" buttons
  - Electric water heater model (or simulation environment)

---

## 🖥️ How It Works

- **🔧 Temperature Setting**:  
  Adjust the temperature using the buttons. Each press increases or decreases the temperature by **5°C**.

- **💾 EEPROM**:  
  Saves and restores the set temperature, ensuring persistence across power cycles.

- **⚙️ Proteus Simulation**:  
  Validate the setup, button inputs, and EEPROM functionality using Proteus.

---

## 📝 Steps to Run the Simulation

1. **🛠️ Set Up**:  
   Create the simulation environment in **Proteus** with the necessary components.

2. **⬆️ Upload**:  
   Flash the embedded code to the microcontroller within the simulation.

3. **▶️ Run**:  
   Execute the simulation and adjust the temperature using the on-screen buttons. The EEPROM will automatically save the changes.

---

## 📌 Future Enhancements

- **🖥️ Add Display**:  
  Integrate an LCD or OLED display to show the current set temperature within the simulation.

- **📡 Remote Control**:  
  Extend the system with remote control features using Proteus-compatible modules.
