/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class BasicOscillatorAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    BasicOscillatorAudioProcessor();
    ~BasicOscillatorAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
//    juce::dsp::Oscillator<float> osc { [](float x) { return std::sin (x); }};
    juce::dsp::Oscillator<float> osc { [](float x) { return x / juce::MathConstants<float>::pi; }, 200};
    juce::dsp::Gain<float> gain;
    
//    std::sin(x); // Sine Wave
//    x / MathConstants<float>::pi; // Saw Wave
//    x < 0.0f ? -1.0f : 1.0f; // Square Wave
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicOscillatorAudioProcessor)
};
