CJSON_MOD_DIR := $(USERMOD_DIR)

# Add all C files to SRC_USERMOD.
SRC_USERMOD += $(CJSON_MOD_DIR)/cJson.c

# We can add our module folder to include paths if needed
# This is not actually needed in this JSON.
CFLAGS_USERMOD += -I$(CJSON_MOD_DIR)
