#🌡️ Electric Water Heater – Adjustable Temperature Control
An embedded system that allows users to adjust and persist the water temperature between 35°C and 75°C, with settings stored in external EEPROM for reliable data retention.

🚀 Features
Adjustable Temperature: Set the water temperature between 35°C and 75°C in 5°C increments.
Simple Controls: Use "Up" and "Down" buttons to adjust the temperature. First button press enters temperature setting mode.
Persistent Settings: Last set temperature is saved in external EEPROM and restored on power-up.
Initial Temperature: Defaults to 60°C on first start.

🛠️ Simulation Setup (Proteus)
Proteus Simulation: The system is simulated in Proteus, a powerful tool for modeling and testing embedded systems.
Components:
Microcontroller (e.g., simulated Arduino)
External EEPROM (e.g., 24CXX series)
Simulated "Up" and "Down" buttons
Electric water heater model (or simulated environment)

🖥️ How It Works
Temperature Setting: Adjust temperature using the buttons. Each press increases/decreases by 5°C.
EEPROM: Saves and restores the set temperature, ensuring persistence after power loss.
Proteus Simulation: The entire setup, including button inputs and EEPROM interaction, is validated through Proteus.

📝 Steps to Run the Simulation
Set Up the simulation environment in Proteus with the necessary components.
Upload the embedded code to the microcontroller in the simulation.
Run the simulation and adjust the temperature using the on-screen buttons. The EEPROM will automatically save your changes.

📌 Future Enhancements
Add a display to show the current set temperature in the simulation.
Extend the simulation with remote control features using Proteus-compatible modules.


