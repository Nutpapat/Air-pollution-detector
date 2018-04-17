# Air-pollution-detector
## Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;สวัสดีครับวันนี้กลุ่ม air pollution detector เราได้สร้างเครื่องแอลพีจีโดยใช้เซ็นเซอร์ MQ7และ MQ135 ที่นำไปใช้กับการตรวจจับอากาศสามารถทำงานได้จริงโดยเครื่องตรวจจับอากาศเราจะนำมาใส่ในรถเพื่อเพิ่มความสะดวกในการตรวจจับอากาศโดยเราไม่ต้องเอาเครื่องไปวางตรวจตามจุดต่างๆเองแต่เราจะใช้ให้รถไปตรวจจับแทนเราและส่งข้อมูลขึ้นเว็บนอกจากนี้ตัวโปรแกรมที่ใช้บังคับรถและเครื่องตรวจจับอากาศยังสร้างจากโปรแกรมarduinoโดยการใช้เพียงภาษา C และ C# ในการเขียนในการเขียน
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ในโครงการนี้เราจะจัดทำเครื่องแอลพีจีเพื่อตรวจสอบมลพิษทางอากาศซึ่งจะตรวจสอบคุณภาพอากาศผ่านเว็บเซิร์ฟเวอร์โดยใช้อินเทอร์เน็ต และจะปส่งสัญญาณเตือนเมื่อคุณภาพอากาศลดลงเกินระดับหนึ่งซึ่งหมายความว่าเมื่อมีจำนวนเพียงพอ ของก๊าซที่เป็นอันตรายอยู่ในอากาศเช่น CO2, ควันแอลกอฮอล์เบนซินและ NH3 จะแสดงคุณภาพอากาศบนหน้าจอ LCD และบนหน้าเว็บเพื่อให้เราสามารถตรวจสอบได้อย่างง่ายดาย
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;เซ็นเซอร์ MQ135 ซึ่งเป็นทางเลือกที่ดีที่สุดสำหรับการตรวจสอบคุณภาพอากาศเนื่องจากสามารถตรวจจับก๊าซที่เป็นอันตรายมากที่สุดและสามารถวัดปริมาณได้อย่างถูกต้องนอกจากนี้คุณสามารถตรวจสอบระดับมลพิษจากที่ใดก็ได้โดยใช้คอมพิวเตอร์หรือโทรศัพท์มือถือของคุณ เราสามารถติดตั้งระบบนี้ได้ทุกที่และยังสามารถเรียกใช้อุปกรณ์บางอย่างเมื่อมลพิษไปเกินระดับบางอย่างเช่นเราสามารถเปิดพัดลมดูดอากาศ
## Required Components
- MQ135 Gas sensor
- MQ7
- Arduino Uno
- เซ็นเซอร์วัดระยะทาง ultrasonic module hc-sr04
- l298n motor driver module
- โครงรถหุ่นยนต์ smart car 2wd robot car
- arduino uno r3 acrylic case box
- Wi-Fi module ESP8266
- ลําโพงอิเล็กทรอนิกส์สัญญาณเตือนภัยออดไฟฟ้า dc 3-24v
- 16X2 LCD
- Breadboard
- power bank
- ที่ใส่ถ่าน
- ถ่าน 4 ก้อน
- สายไฟจัมเปอร์
Create README.md
