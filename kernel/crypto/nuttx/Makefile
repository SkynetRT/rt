include ../../../Make.defs
INC = ../../..
OBJS := aes.o bn.o cmac.o cryptosoft.o ecb_enc.o hmac_buff.o md5.o rijndael.o sha1.o testmngr.o \
	blake2s.o cast.o crypto.o curve25519.o gmac.o idgen.o poly1305.o rmd160.o sha2.o xform.o \
	blf.o chachapoly.o cryptodev.o ecb3_enc.o hmac.o key_wrap.o random_pool.o set_key.o siphash.o
.PHONY: all
all: crypto.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
crypto.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) crypto.a *.d
