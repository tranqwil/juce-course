namespace tremolo {
PluginEditor::PluginEditor(PluginProcessor& p)
: AudioProcessorEditor(&p),
  modulationRateAttachment(p.getParameterRefs().rate, modulationRateSlider),
  modulationDepthAttachment(p.getParameterRefs().depth, modulationDepthSlider),
  gainAttachment(p.getParameterRefs().gain, gainSlider),
  bypassedAttachment(p.getParameterRefs().bypassed, bypassedButton)

{
  setLookAndFeel(&customLookAndFeel);
  background.setImage(juce::ImageCache::getFromMemory(
      assets::Background_png, assets::Background_pngSize));

    //logo.setImage(
    // juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));

  modulationRateSlider.setPopupDisplayEnabled(true, true, this);
  modulationRateSlider.setTextValueSuffix("Hz");


  modulationDepthSlider.setPopupDisplayEnabled(true, true, this);


  gainSlider.setPopupDisplayEnabled(true, true, this);
  gainSlider.setTextValueSuffix("dB");


  addAndMakeVisible(background);
  //addAndMakeVisible(logo);
  addAndMakeVisible(lfoVisualizer);
  addAndMakeVisible(modulationRateSlider);
  addAndMakeVisible(modulationDepthSlider);
  addAndMakeVisible(gainSlider);
  addAndMakeVisible(bypassedButton);

  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(540, 270);
}

PluginEditor::~PluginEditor()
{
  setLookAndFeel(nullptr);
}

void PluginEditor::resized() {
  auto bounds = getLocalBounds();
  background.setBounds(bounds);

  //logo.setBounds({16, 16, 105, 24});
  lfoVisualizer.setBounds({135, 160, 270, 64});

  modulationRateSlider.setBounds({132, 45, 80, 80});
  modulationDepthSlider.setBounds({228, 45, 80, 80});
  gainSlider.setBounds({332, 45, 80, 80});

  bypassedButton.setBounds(484, 0, 56, 56);


}
}  // namespace tremolo
