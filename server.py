import paho.mqtt.client as mqtt

class RCS_Server(mqtt.Client):
    """Class handling RCS MQTT Server Process."""

    def __init__(self) -> None:

        super().__init__(
            client_id="Track",
            reconnect_on_failure=True
        )

    # def on_message(client, userdata, msg):
    #     print(msg.topic+" "+str(msg.payload))

    def on_message(self, client, userdata, msg) ->  None:
        print(msg.topic+" "+str(msg.payload))
        return super().on_message

    def on_connect(self, client, userdata, flags, rc):
        print("Connection returned result: "+ mqtt.connack_string(rc))

        """
            $SYS/broker/clients/total b'n'
            $SYS/broker/clients/active b'n'
            $SYS/broker/clients/connected b'n'
        """
        # self.subscribe("$SYS/broker/clients/#")




class RCS_Track:
    """Class handling RCS Track State."""


client = RCS_Server()

client.connect("192.168.1.153", 1883, 60)

client.loop_start()

while True:
    # temperature = sensor.blocking_read()
    client.publish("flags", "red")
