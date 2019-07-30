# Programmable Motion Detector

This is an open-source programmable motion detector to switch a voltage when some movement happened. The actual motion sensor is the [RCWL0516](https://github.com/jdesbonnet/RCWL-0516) which you can get for cheap on Amazon or eBay.

This consists of an ATTiny85 which can be programmed. GPIO2 is detecting if a motion has happened and GPIO1 is triggering the MOSFET. To flash a ATTiny85 you can follow this tutorial: [http://highlowtech.org/?p=1695](http://highlowtech.org/?p=1695)
I am using an Adruino Pro Mini and a TTL USB Stick.

#### the device can switch 7V-35V with max 30A (it propably needs a heatsink if it is more then 3A)

### [EasyEDA Public Project](https://easyeda.com/mirko.haeberlin/replace-light-switch)

### [Gerber file](./Gerber_motion-detector.zip)
<img src="./img/pcb_front.svg">
<img src="./img/pcb_back.svg">

### [Schematic Pdf](./Schematic_motion-detector.pdf)
<img src="./img/Schematic_motion-detector.png">

### Datasheets

#### [IRLZ44N](http://www.irf.com/product-info/datasheets/data/irlz44n.pdf)
#### [L7805](https://www.jameco.com/Jameco/Products/ProdDS/924570.pdf)
