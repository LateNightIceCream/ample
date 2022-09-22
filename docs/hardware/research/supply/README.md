# Supply Components

## Charge Pump
A charge pump is used to get a negative voltage w.r.t. ground and provide some headroom for the operational amplifiers.
The whole ic takes at max 12 mA. So 12 mA * 3 = 60 mA that the charge pump should be able to sink. Inverting switching regulators are a little overkill imo because of the additional inductance and perhaps diodes and the usually way too large output current capability.
