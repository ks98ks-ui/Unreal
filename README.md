# First

Unreal Engine 기반으로 만든 개인 학습용 프로젝트입니다.
C++ 게임플레이 코드와 Unreal 에셋을 함께 사용하며, 여러 실습 내용을 한 저장소에서 관리하고 있습니다.

## 프로젝트 소개

이 저장소에는 개인적으로 학습한 Unreal 프로젝트 내용이 들어 있습니다.
Blueprint 에셋, 맵, 애니메이션, 사운드 같은 콘텐츠와 함께 직접 작성한 C++ 클래스도 포함되어 있습니다.
또한 아이템 시스템과 여러 플레이 스타일 실습을 함께 담고 있습니다.

## 폴더 구성

- `First.uproject`: Unreal 프로젝트 실행 파일
- `Source/First`: C++ 게임플레이 클래스와 모듈 코드
- `Content/`: Unreal 에셋, 맵, Blueprint, 애니메이션, 오디오, Starter Content
- `Config/`: Unreal 프로젝트 설정 파일

## 작업 흐름

1. Unreal Engine에서 `First.uproject`를 엽니다.
2. 필요하면 Visual Studio 프로젝트 파일을 생성합니다.
3. Visual Studio 또는 Unreal Editor에서 빌드 후 실행합니다.
4. 에디터 안에서 게임플레이 동작을 테스트합니다.

## Git 관리

이 저장소는 큰 Unreal 에셋 파일 관리를 위해 Git LFS를 사용합니다.
`*.uasset`, `*.umap` 같은 바이너리 자산은 이후 변경분부터 LFS 규칙을 따라 관리됩니다.
기존 `unreal 1` 히스토리는 그대로 유지되고, LFS 설정은 이후 커밋부터 적용됩니다.
