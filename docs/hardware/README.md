# Hardware Concept
## Starting Point / Motivation
- Tensai 'Amplifier System 55'

## Requirements
- [ ] >=15W speaker output for at least two speakers (L/R)
- [ ] headphone output
- [ ] volume control
- [ ] front power button
- [ ] source selection
  - line input (single ended)
  - S/PDIF input
  - (maybe) Bluetooth input
- [ ] Microcontroller
- [ ] some LEDs

### Optional
- [ ] reuse tensai transformer
  - its very heavy and takes up a lot of space!
- [ ] Bluetooth input
- [ ] keep input / user interface in direction of uC extendable
- [ ] configuration jumpers on back of case

### Case
- either a new wooden case or original Tensai case (bad for BT signal)

## Realization
### ICs

### Block Diagram

### Voltage Levels
| Voltage | Description              |
|---------|:------------------------:|
| 230 VAC | wall                     |
| ???     | transformer secondary    |
| ???     | class D amplfier voltage |
| 5 V     | codec supply             |
| 3.3 V   | uC voltage               |
| 3.3 V   | codec supply             |

- make sure to use ferrite beads + caps to decouple individual codec supplies


