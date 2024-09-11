set(srcs "main.c"
         "gatt_svr.c"
         "ledcontrol.c")

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS ".")
