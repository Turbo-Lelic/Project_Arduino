#include <SPI.h>
#include <SD.h>

Sd2Card card;
SdVolume partition;
SdFile root;
void setup()
{
Serial.begin(9600);
while (!Serial);
if (!card.init(SPI_HALF_SPEED))
{
Serial.println("initialization\failed");
while(true);
}
else
Serial.println("Card OK");
switch (card.type())
{
case SD_CARD_TYPE_SD1:
Serial.println("SD1");
break;
case SD_CARD_TYPE_SD2:
Serial.println("SD2");
break;
case SD_CARD_TYPE_SDHC:
Serial.println("SDHC");
break;
default:
Serial.println("Unknown type");
}
if (!partition.init(card))
{
Serial.println("No partition found.\Make sure card is\is formatted as\FAT16 or FAT32");
while(true);
}
uint32_t part_size;
part_size = partition.blocksPerCluster();
part_size *= partition.clusterCount();
part_size /= 2;
part_size /= 1024;
Serial.print("Partition size in Mb: ");
Serial.println(part_size);
Serial.print("Partition size in Gb: ");
Serial.print(float(part_size) / 1024.0);
Serial.println("Root directory:");
root.openRoot(partition);
root.ls (LS_R | LS_SIZE, 3);
}
void loop()
{

}
