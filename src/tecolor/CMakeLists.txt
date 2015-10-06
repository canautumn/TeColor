set(TECOLOR_SOURCE_FILES Spectra.cpp ColorMatchingFunction.cpp EigenUtils.cpp Illuminant.cpp Primaries.cpp Tristimulus.cpp SpectralKit.cpp ReflectanceSet.cpp CIELAB.cpp ColorimetryKit.cpp AppearanceKit.cpp)

add_library(tecolor ${TECOLOR_SOURCE_FILES})
