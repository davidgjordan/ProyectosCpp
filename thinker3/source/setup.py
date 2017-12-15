from distutils.core import setup, Extension

module1 = Extension('calculadora', sources=['calculadora.cpp'])

setup(name='calculadora',
      version='1.0',
      description='This is a demo package',
      ext_modules=[module1])
