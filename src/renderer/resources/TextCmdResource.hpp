#pragma once

#include <abyssgraphics/resource/resources/AsyncResource.hpp>
#include <abyssgraphics/resource/resources/TextResource.hpp>

class CTextCmdResource : public Abyssgraphics::IAsyncResource {
  public:
    CTextCmdResource(Abyssgraphics::CTextResource::STextResourceData&& data);
    virtual ~CTextCmdResource() = default;

    virtual void render();

  private:
    Abyssgraphics::CTextResource::STextResourceData m_data;
};
