# FakeSwitch
Steps to build the fake switch application

1. Directory layout:
```
     myworkspace/
        fakeswitch/
           FakeSwitch/ <- clone the repo here
```
2. Go to fakeswitch folder and move the feed to the right location:
```
mv FakeSwitch/feed/Makefile .
```
3. Go to sdk folder
  - ```./scripts/feeds update -a && ./scripts/feeds install -a```
  - Select fake-switch in make menuconfig
  - ```make package/fakeswitch/compile -j1 V=s```
