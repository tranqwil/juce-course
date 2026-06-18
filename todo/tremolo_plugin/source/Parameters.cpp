
namespace tremolo {
namespace {
juce::AudioParameterFloat& createModulationRateParameter(juce::AudioProcessor& processor) {
  constexpr auto versionHint = 1;

  auto parameter = std::make_unique<juce::AudioParameterFloat>(
    juce::ParameterID{"modulation.rate", versionHint},
    "Modulation Rate",
    juce::NormalisableRange{0.1f, 40.0f, 0.01f, 0.4f, false},
    5.0f,
    juce::AudioParameterFloatAttributes{}.withLabel("Hz"));
  auto& parameterReference = *parameter;
  processor.addParameter(parameter.release());
  return parameterReference;
}

juce::AudioParameterFloat& createGainParameter(juce::AudioProcessor& processor) {
  constexpr auto versionHint = 1;

  auto parameter = std::make_unique<juce::AudioParameterFloat>(
    juce::ParameterID{"gain", versionHint},
    "Gain",
    juce::NormalisableRange{-12.0f, 12.0f, 0.1f, 1.0f, false},
    0.0f,
    juce::AudioParameterFloatAttributes{}.withLabel("dB"));
  auto& parameterReference = *parameter;
  processor.addParameter(parameter.release());
  return parameterReference;
}
}
Parameters::Parameters(juce::AudioProcessor& processor)
// TODO: create parameters
// TODO: retrieve references to parameters
// TODO: add parameters to the processor
: rate{createModulationRateParameter(processor)},
 gain{createGainParameter(processor)}
{

}
}  // namespace tremolo
