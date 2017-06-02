# Arduino-SunTrackingSolarPanel
Sun tracking Solar Panel with Arduino Uno

Osallistuimme Tero Karvisen ohjaamalle Prototyypin rakentaminen -kurssille, jossa tavoitteena oli tehdä jokin sulautetun järjestelmän prototyyppi viikossa. Toteutukseen oli tarjolla mm. Arduino Uno ja ESP8266-12E -mikrokontrollereita, sekä lukuisia erilaisia sensoreita ja muita komponentteja. 

# Maanantai
Päätimme toteuttaa Arduinolla ohjatun aurinkosensorin ja sensorin avulla ohjattavan aurinkopaneeliasetelman. Idea kurssin työksi löytyi helposti, ja saimmekin myös heti sen toteuttamiseen tarvittavat komponentit. Valoisuustason mittaamiseen käytimme neljää LDR-sensoria (Light Dependent Resistor), joiden arvojen mukaan paneeli kääntyy aurinkoa kohti. Kytkennät tehtiin Arduinon Sensor Shieldiä käyttäen, jotta vältyttäisiin lukuisten hyppylankojen aiheuttamalta ns. ”johtospagetilta”.
# Tiistai

Toisena päivänä saimme työstettyä koodin jo muotoon, jossa saimme sensorit seuraamaan kirkkainta valonlähdettä (testattu puhelimen taskulampulla). Koodiin lisättiin myöhemmin myös sallitut liikkumarajat aurinkopaneelille (aurinko ei paista Suomeen pohjoisesta tai suoraan ylhäältä päin). Koodi alustaa servot vakioasentoon ja aloittaa valoisuuden seurannan. Valoisuustasoja vertaamalla saadaan tietoon kirkkaimman valonlähteen (auringon) sijainti, jota kohti servot säätävät paneelia. Aloitimme projektin tukirakenteen suunnittelun sekä osien etsinnän. Projektiin hankittiin 2kpl Bilteman pihalampuista purettua aurinkopaneelia, joiden juotokset olivat kuitenkin valitettavasti niin huonolaatuisia, ettei suunniteltua jännitemittausta saatu toteutettua. 
# Keskiviikko

Kolmantena päivänä mittasimme olemassa olevat komponentit ja siirsimme mitat Blenderiin, jossa suunnittelimme tukirakenteen suoraan komponenttien oikeilla mitoilla. Tämän avulla vähennettiin teippailun ym. säätämisen tarvetta, sekä pienennettiin laitteen kokoa. Tukirakennetta suunnitellessa otettiin huomioon myös johtojen asettelu niin, ettei ääriasennoissakaan pitäisi tulla ongelmia johtojen pituuden takia. Johdot paketoitiin johtosuojiin sekä ulkonäön vuoksi, että kytkentöjen turvaamiseksi. Arduinolle ja Sensor Shieldille suunniteltiin kotelo, jotta lopullinen toteutus saataisiin siistin näköiseksi.
# Torstai

Viimeisenä kokonaisena päivänä keskityimme lähinnä ongelmanratkaisuun, viimeistelyyn sekä 3D-tulostuksiin. Koodi muutettiin käyttämään tarkempia, itse määriteltyjä pulsseja helpomman ja epätarkemman servo.h -kirjaston sijaan. 3D-tulostetut osat viimeisteltiin ja kasattiin valmiiksi kokonaisuudeksi. 
# Perjantai

Projektien esittelypäivä! Aamupäivällä ehdimme vielä tehdä viimeistelyjä niin fyysisten osien kuin koodinkin parissa, sekä valmistella materiaaleja julkaisuun. Kurssista ja erityisesti omasta projektista voi olla tyytyväinen, sillä lopputuloksesta ei ihan heti arvaisi viikon rakennusaikaa.
# Käytetyt osat

•	Arduino Uno R3
•	Arduino Sensor Shield
•	2x servo
•	4x LDR-valosensori
•	hyppylankoja
•	3D-tulostettu tukirakenne/kotelo
•	2kpl purettua pihavaloa (aurinkokennokäyttöisiä)

# Kytkennät

LDR-sensorien arvoja luetaan Arduinon analogipinneistä 0-3, ja servoja ohjataan digitaalipinneillä 2 ja 3. Johdot on kytketty selkeyden vuoksi Arduinoon kiinnitettyyn Sensor Shieldiin. Erilisiä vastuksia toteutuksemme ei tarvitse, sillä käytämme Arduinon sisäänrakennettuja ylösvetovastuksia.

•	A0 – LDR vasen yläreuna
•	A1 – LDR oikea yläreuna
•	A2 – LDR vasen alareuna
•	A3 – LDR oikea alareuna
•	D2 – Servo vaakaliike
•	D3 – Servo pystyliike

# Linkit
Joonas Valsta blogi: https://joonashaagaheliavalstalinuxpalvelimena.wordpress.com/2017/06/02/prototyypin-rakentaminen-29-5-2-6-2017-haaga-helia/
Jussi Isosomppi blogi: https://jisosomppi.wordpress.com/2017/06/02/prototyypin-rakentaminen-haaga-helia-29-5-2-6-2017/

# Lähteet
http://botbook.com
http://sulautetut.fi
http://terokarvinen.com/2017/prototyypin-rakentaminen-bus4tn007-8-w22
