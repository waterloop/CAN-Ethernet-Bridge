Software for G5's CAN - Ethernet bridge.

### Build Instructions

**Dependencies**

* GCC
* Make
* Bash

Navigate to the project's root directory:

```bash
cd /path/to/project/directory
```

To build the software for the Raspberry Pi:

```bash
cd RPI
make
```

To build the software for the STM32F402K6Tx:

```bash
cd STM32F402K6Tx
make
```

It can also be built inside of the STM32CubeIDE.