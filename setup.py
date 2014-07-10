from distutils.core import setup, Extension

crypto_hash_module = Extension('crypto_hash',
                               sources = ['cryptomodule.c',
                                          'crypto.c',
										  'sha3/blake.c',
										  'sha3/bmw.c',
										  'sha3/groestl.c',
										  'sha3/jh.c',
										  'sha3/keccak.c',
										  'sha3/skein.c',
										  'sha3/cubehash.c',
										  'sha3/echo.c',
										  'sha3/luffa.c',
										  'sha3/simd.c',
										  'sha3/shavite.c',
                                                                                  'sha3/hamsi.c',
                                                                                  'sha3/fugue.c',
                                                                                  'sha3/shabal.c',
                                                                                  'sha3/whirlpool.c',
                                                                                  'sha3/haval.c',
                                                                                  'sha3/sha2big.c'],   
                               include_dirs=['.', './sha3'])

setup (name = 'crypto_hashs',
       version = '1.0',
       description = 'Bindings for proof of work used by cryptohash',
       ext_modules = [crypto_hash_module])
