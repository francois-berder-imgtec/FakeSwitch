# FakeSwitch
Steps to make the fake switch application
1)Directory layout
     myworkspace/
        fakeswitch/
           FakeSwitch/ <- clone the repo here
2)Go to fakeswitch folder
     mv FakeSwitch/feed/Makefile .
3)Go to sdk folder
    ./scripts/feeds update -a && ./scripts/feeds install -a
    Select fake-switch in make menuconfig
    make package/fakeswitch/compile -j1 V=s
