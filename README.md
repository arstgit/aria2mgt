# aria2mgt

Extract hash info from aria2 control file. Used for resuming download job. `Linux only`.



## Compile & Install

```
  $ make && make install
```

## Usage

```
  $ aria2mgt example.aria2 | xargs -0 aria2c
```
