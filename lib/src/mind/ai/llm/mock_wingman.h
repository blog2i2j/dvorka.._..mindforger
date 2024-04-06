/*
 mock_wingman.h     MindForger thinking notebook

 Copyright (C) 2016-2024 Martin Dvorak <martin.dvorak@mindforger.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef M8R_MOCK_WINGMAN_H
#define M8R_MOCK_WINGMAN_H

#include "wingman.h"

namespace m8r {

/**
 * Mock Wingman implementation.
 */
class MockWingman: Wingman
{
public:
    static constexpr const auto LLM_MODEL_MOCK = "mock-llm-model";

private:
    std::vector<std::string> llmModels;
    std::string llmModel;

public:
    explicit MockWingman(const std::string& llmModel);
    MockWingman(const MockWingman&) = delete;
    MockWingman(const MockWingman&&) = delete;
    MockWingman& operator =(const MockWingman&) = delete;
    MockWingman& operator =(const MockWingman&&) = delete;
    ~MockWingman() override;

    virtual std::vector<std::string>& listModels() {
        return this->llmModels;
    }

    std::string getWingmanLlmModel() const { return llmModel; }
    virtual void chat(CommandWingmanChat& command) override;
    virtual void embeddings(CommandWingmanEmbeddings& command) override {
        UNUSED_ARG(command);
    }

};

}
#endif // M8R_MOCK_WINGMAN_H
