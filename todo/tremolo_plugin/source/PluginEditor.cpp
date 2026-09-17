namespace tremolo {
PluginEditor::PluginEditor(PluginProcessor& p)
: AudioProcessorEditor(&p),
  modulationRateAttachment(p.getParameterRefs().rate, modulationRateSlider),
  modulationDepthAttachment(p.getParameterRefs().depth, modulationDepthSlider),
  gainAttachment(p.getParameterRefs().gain, gainSlider)

{
  background.setImage(juce::ImageCache::getFromMemory(
      assets::Background_png, assets::Background_pngSize));

    logo.setImage(
      juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));

  modulationRateSlider.setPopupDisplayEnabled(true, true, this);
  modulationRateSlider.setTextValueSuffix("Hz");

  modulationDepthSlider.setPopupDisplayEnabled(true, true, this);

  gainSlider.setPopupDisplayEnabled(true, true, this);
  gainSlider.setTextValueSuffix("dB");

  addAndMakeVisible(background);
  addAndMakeVisible(logo);
  addAndMakeVisible(lfoVisualizer);
  addAndMakeVisible(modulationRateSlider);
  addAndMakeVisible(modulationDepthSlider);
  addAndMakeVisible(gainSlider);

  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(540, 270);
}

void PluginEditor::resized() {
  auto bounds = getLocalBounds();
  background.setBounds(bounds);

  logo.setBounds({16, 16, 105, 24});
  lfoVisualizer.setBounds({18, 149, 504, 92});
  modulationRateSlider.setBounds({90, 40, 80, 80});
  modulationDepthSlider.setBounds({230, 40, 80, 80});
  gainSlider.setBounds({390, 40, 80, 80});


}
}  // namespace tremolo
