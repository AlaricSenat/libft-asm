## Auto generated make tool, don't edit manually.

OBJ_FILES_src := ft_atoi.o \
                 ft_bzero.o \
                 ft_cat.o \
                 ft_isalnum.o \
                 ft_isalpha.o \
                 ft_isascii.o \
                 ft_isdigit.o \
                 ft_isprint.o \
                 ft_isspace.o \
                 ft_memchr.o \
                 ft_memcpy.o \
                 ft_memmove.o \
                 ft_memset.o \
                 ft_puts.o \
                 ft_strcat.o \
                 ft_strcmp.o \
                 ft_strdup.o \
                 ft_strlen.o \
                 ft_tolower.o \
                 ft_toupper.o

OBJECTS += $(patsubst %, src/$(OBJECT_DIR)/%, $(OBJ_FILES_src))