#include<stdio.h>
#include<stdlib.h>

struct Sensor
{
	int id;
	char name[50];
	int version;

	union
	{
		float temperature;
		float humidity;
		char motion[4];
	};
};

#define SENSOR_TEMPERATURE 1
#define SENSOR_HUMIDITY 2

int main()
{

	system("clear");

	struct Sensor temp = {SENSOR_TEMPERATURE, "Temperature", 0x00010001 };
	struct Sensor hum = {SENSOR_HUMIDITY, "Humidity", 0x00020001 };

	temp.temperature = 25.26;
	hum.humidity = 4.56;
		
	printf("size of Sensor: %d\n", sizeof( struct Sensor) );

	printf("\n*** Sensor Temperature ***\n");
	printf("ID:%d\nName:%s\nVersion:%x\nTemperature:%.2f\n", temp.id, temp.name, temp.version, temp.temperature);

	printf("\n*** Sensor Humidity ***\n");
	printf("ID:%d\nName:%s\nVersion:%x\nHumidity:%.2f\n", hum.id, hum.name, hum.version, hum.humidity);

	return 0;
}
