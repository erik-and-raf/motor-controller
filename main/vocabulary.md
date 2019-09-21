# Bluetooth Vocabulary

**GAP** (Generic Access Profile)

- General topolgy of the GLE network stack
- Peripheral
  - A device that advertises its presence so central devices can establish a connection. After connecting, peripherals no longer broadcast data to other central devices and stay connected to the device that accepted connection request.
  - Peripherals are low-power because they only have to send beacons periodically. Central devices are responsible for starting communication with peripherals.
A device that initiates a connection with a peripheral device by first listening to the advertising packets.

- Central 
  - A central device can connect to many other peripheral devices.
When the central device wants to connect, it sends a request connection data packet to the peripheral device. If the peripheral device accepts the request from the central device, a connection is established.

**GATT (Generic Attribute Profile)**

- Describes in detail how attributes data are transferred once devices have a dedicated connection

**HCI (Host Controller Interface)** 


**MTU** Maximum length of the ATT packet (23)




