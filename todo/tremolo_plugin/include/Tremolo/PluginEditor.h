#pragma once

namespace tremolo {
class PluginEditor : public juce::AudioProcessorEditor {
public:
  explicit PluginEditor(PluginProcessor&);
  ~PluginEditor() override;

  void resized() override;

private:
  juce::ImageComponent background;
  juce::ImageComponent logo;
  LfoVisualizer lfoVisualizer;

  // controls
  juce::Slider modulationRateSlider{juce::Slider::SliderStyle::RotaryVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox};
  juce::SliderParameterAttachment modulationRateAttachment;
  juce::Slider modulationDepthSlider{juce::Slider::SliderStyle::RotaryVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox};
  juce::SliderParameterAttachment modulationDepthAttachment;
  juce::Slider gainSlider{juce::Slider::SliderStyle::RotaryVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox};
  juce::SliderParameterAttachment gainAttachment;
  juce::ToggleButton bypassedButton{"Bypassed"};
  juce::ButtonParameterAttachment bypassedAttachment;
  juce::ComboBox waveformComboBox{"Waveform"};
  juce::ComboBoxParameterAttachment waveformAttachment;
  CustomLookAndFeel customLookAndFeel;




  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
}  // namespace tremolo
