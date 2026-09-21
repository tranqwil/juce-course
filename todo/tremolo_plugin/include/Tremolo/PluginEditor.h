#pragma once

namespace tremolo {
class PluginEditor : public juce::AudioProcessorEditor {
public:
  explicit PluginEditor(PluginProcessor&);

  void resized() override;

private:
  juce::ImageComponent background;
  juce::ImageComponent logo;
  LfoVisualizer lfoVisualizer;

  // controls
  juce::Slider modulationRateSlider{juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox};
  juce::SliderParameterAttachment modulationRateAttachment;
  juce::Slider modulationDepthSlider{juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox};
  juce::SliderParameterAttachment modulationDepthAttachment;
  juce::Slider gainSlider{juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag, juce::Slider::TextEntryBoxPosition::NoTextBox};
  juce::SliderParameterAttachment gainAttachment;




  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
}  // namespace tremolo
