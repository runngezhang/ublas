TEMPLATE = app
TARGET = bench5

!include (../configuration.pri)

OTHER_FILES += \
    ../../../../benchmarks/bench5/Jamfile.v2

SOURCES += \
    ../../../../benchmarks/bench5/assignment_bench.cpp
