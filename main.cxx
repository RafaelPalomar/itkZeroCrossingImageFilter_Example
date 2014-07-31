#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkZeroCrossingImageFilter.h"

#include <iostream>

typedef itk::Image<float, 3> ImageType;
typedef itk::ImageFileReader<ImageType> ReaderType;
typedef itk::ImageFileWriter<ImageType> WriterType;
typedef itk::ZeroCrossingImageFilter<ImageType, ImageType> ZeroCrossingType;

int main(int argc, char **argv)
{

  ImageType::Pointer image = ImageType::New();

  if(argc != 3)
    {
    std::cerr << "Wrong number of arguments" << std::endl;
    }

  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(argv[1]);
  reader->Update();

  ZeroCrossingType::Pointer zeroCrossingFilter = ZeroCrossingType::New();
  zeroCrossingFilter->SetInput(reader->GetOutput());

  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName(argv[2]);
  writer->SetInput(zeroCrossingFilter->GetOutput());
  writer->Update();

  return 0;
}
